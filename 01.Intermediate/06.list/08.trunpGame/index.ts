// テーブルのインターフェースを定義
interface Table {
    players: Card[][];
    gameMode: string;
    deck: Deck;
}

class Card {
    public suit: string;
    public value: string;
    public intValue: number;
    constructor(suit: string, value: string, intValue: number) {
        this.suit = suit;
        this.value = value;
        this.intValue = intValue;
    }
    public getCardString(): string {
        return `${this.suit}${this.value}(${this.intValue})`;
    }
}

class Deck {
    public deck: Card[];
    constructor() {
        this.deck = Deck.generateDeck();
    }
    public static generateDeck(gameMode: string = null): Card[] {
        let newDeck: Card[] = [];
        const suits = ["♣", "♦", "♥", "♠"];
        const values = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"];
        const blackJack = new Map<string, number>();
        blackJack.set("A", 1);
        blackJack.set("J", 10);
        blackJack.set("Q", 10);
        blackJack.set("K", 10);
        for (let i = 0; i < suits.length; i++) {
            for (let j = 0; j < values.length; j++) {
                let currentValue = values[j];
                let intValue = gameMode === "21" ? (currentValue in blackJack ? blackJack.get(currentValue) : parseInt(currentValue)) : j + 1;
                newDeck.push(new Card(suits[i], values[j], intValue));
            }
        }
        return newDeck;
    }
    public printDeck(): void {
        console.log("Displaying cards...");
        for (let i = 0; i < this.deck.length; i++) {
            console.log(this.deck[i].getCardString());
        }
    }
    public shuffleDeck(): void {
        for (let i = 0; i < this.deck.length; i++) {
            const index = Math.floor(Math.random() * (i + 1));
            const temp = this.deck[index];
            this.deck[index] = this.deck[i];
            this.deck[i] = temp;
        }
    }
    public draw(): Card {
        return this.deck.pop();
    }
}

// ディーラークラス
class Dealer {
    // 参加人数を受け取り、それぞれのプレイヤーにカードを配る処理を作成します。
    public static startGame(amountOfPlayers: number, gameMode: string): Table {
        // テーブルの情報を作成(players: Card[], deck: Deck)
        let table: Table = {
            players: [],
            gameMode: gameMode,
            deck: new Deck(),
        };
        // デッキをシャッフルします
        table.deck.shuffleDeck();
        // プレイヤー分繰り返し
        for (let i = 0; i < amountOfPlayers; i++) {
            let playerCard: Card[] = [];
            // 手札を指定された枚数分ドローする
            for (let j = 0; j < Dealer.initialCards(gameMode); j++) {
                playerCard.push(table.deck.draw());
            }
            table.players.push(playerCard);
        }
        // tableのプレイヤー全員の手札を返す
        return table;
    }
    // ゲームの内容によって手札を変える
    public static initialCards(gameMode: string): number {
        if (gameMode == "poker") return 5;
        if (gameMode == "21") return 2;
    }
    // 卓の情報を表示するメソッド
    public static printTableInformation(table: Table) {
        console.log(`Amount of players:${table.players.length}...Game mode:${table.gameMode}. At this table: `);
        for (let i = 0; i < table.players.length; i++) {
            console.log(`Player${i + 1}'s hand is: `);
            for (let j = 0; j < table.players[i].length; j++) {
                console.log(table.players[i][j].getCardString());
            }
        }
    }
    // 各プレーヤーの手札を受け取って、合計値を計算するscore21Individualメソッドを作成します。
    // ブラックジャックでは値の合計値が21を超えるとNGなのでその場合は0とします。
    public static score21Individual(cards: Card[]): number {
        let value = 0;
        for (let i = 0; i < cards.length; i++) {
            value += cards[i].intValue;
        }
        return value > 21 ? 0 : value;
    }
    // ブラックジャックで誰が勝利したか表示する関数を作成します。
    // それぞれのプレイヤーの手札をscore21Individualで計算し、配列に保存します。例: [10,16,15,16,15,15]
    // この場合、勝利するプレイヤーが複数存在することから、cache[10] = 1, cache[15] = 3, cache[16] = 2のように書き換えます。
    // 配列 [10,16,15,16,15,15]の最大値は16で、cache[16] > 1なのでドローになります。
    // もし、0 <= cache[16] <= 1なら、そのプレイヤーの勝利、それ以外の場合は勝者が誰もいないことになります。
    // ではこのロジックを関数にしてみましょう。
    public static winnerOf21(table: Table): string {
        // プレイヤーの手札の合計を入れるための配列を作成
        let points = [];
        // 得点の出現回数をまとめたハッシュマップ
        let cache = {};
        for (let i = 0; i < table.players.length; i++) {
            let point = Dealer.score21Individual(table.players[i]);
            points.push(point);

            if (cache[point] >= 1) cache[point] += 1;
            else cache[point] = 1;
        }
        // 各プレイヤーの得点を確認します。
        console.log(points);
        // 最大の点数を出している位置を特定する
        let winnerIndex = HelperFunctions.maxInArrayIndex(points);
        if (cache[points[winnerIndex]] > 1) return "It is a draw ";
        else if (cache[points[winnerIndex]] >= 0) return `player ${winnerIndex + 1} is the winner`;
        else return "No winners..";
    }
    // 卓のゲームの種類によって勝利条件を変更するcheckWinnerというメソッドを作成します。
    static checkWinner(table: Table) {
        if (table["gameMode"] == "21") return Dealer.winnerOf21(table);
        else return "no game";
    }
}

// 計算のみを行うHelperFunctionsクラスを定義
class HelperFunctions {
    // 数値で構成される配列を受け取り、最大値のインデックスを返します。
    public static maxInArrayIndex(intArr: number[]) {
        let maxIndex = 0;
        let maxValue = intArr[0];
        for (let i = 0; i < intArr.length; i++) {
            if (maxValue < intArr[i]) {
                maxValue = intArr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}

let table1 = Dealer.startGame(1, "poker");
let table2 = Dealer.startGame(3, "21");

Dealer.printTableInformation(table1);
console.log(Dealer.checkWinner(table1));

Dealer.printTableInformation(table2);
console.log(Dealer.checkWinner(table2));

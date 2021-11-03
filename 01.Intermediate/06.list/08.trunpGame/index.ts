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
    public static generateDeck(): Card[] {
        let newDeck: Card[] = [];
        const suits = ["♣", "♦", "♥", "♠"];
        const values = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"];
        for (let i = 0; i < suits.length; i++) {
            for (let j = 0; j < values.length; j++) {
                newDeck.push(new Card(suits[i], values[j], j + 1));
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
}

// PlayerAの手札
let card1 = new Card("♦︎", "A", 1);
let card2 = new Card("♦︎", "J", 11);

// PlayerBの手札
let card3 = new Card("♦︎", "9", 9);
let card4 = new Card("♦︎", "K", 13);

console.log(Dealer.score21Individual([card1, card2]));
console.log(Dealer.score21Individual([card3, card4]));

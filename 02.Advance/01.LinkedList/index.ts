// number型のノード
class NumNode {
    public data: number;
    public next: NumNode | null;
    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
}

// 片方向連結リスト
class SinglyLinkedList {
    public head: NumNode | null;
    constructor(arr?: number[]) {
        this.head = arr.length > 0 ? new NumNode(arr[0]) : new NumNode(null);

        let currentNode = this.head;
        for (let i = 1; i < arr.length; i++) {
            currentNode.next = new NumNode(arr[i]);
            currentNode = currentNode.next;
        }
    }
    // 走査
    public scanning(): void {
        let currentNode = this.head;
        return this.scanningHelper(currentNode);
    }
    private scanningHelper(currentNode: NumNode): void {
        if (currentNode === null) return;
        console.log(currentNode.data);
        return this.scanningHelper(currentNode.next);
    }
    // 与えられたインデックスまでリストを反復する
    public at(index: number): NumNode | null {
        return this.atHelper(index, this.head);
    }
    private atHelper(index: number, currentNode: NumNode): NumNode | null {
        if (currentNode === null) return null;
        if (index <= 0) return currentNode;
        return this.atHelper(index - 1, currentNode.next);
    }
    public findNode(value: number): number | null {
        return this.findNodeHelper(value, this.head, 0);
    }
    private findNodeHelper(value: number, currentNode: NumNode, count: number): number | null {
        if (currentNode === null) return null;
        if (currentNode.data === value) return count;
        return this.findNodeHelper(value, currentNode.next, count + 1);
    }
}

const numList = new SinglyLinkedList([35, 23, 546, 67, 86, 234, 56, 767, 34, 1, 98, 78, 555]);

console.log(numList.at(2).data);
console.log(numList.at(12).data);
console.log(numList.findNode(234));
console.log(numList.findNode(67));
console.log(numList.findNode(767));

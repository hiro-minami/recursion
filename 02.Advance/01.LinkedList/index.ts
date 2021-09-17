class NumNode {
    public data: number | null;
    public next: NumNode | null;
    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
    public addNextNode(newNode: NumNode): void {
        let temp = this.next;
        this.next = newNode;
        newNode.next = temp;
    }
}

class SinglyLinkedList {
    public head: NumNode;
    constructor(arr: number[] | null) {
        this.head = arr.length > 0 ? new NumNode(arr[0]) : new NumNode(null);
        let currentNode = this.head;
        for (let i = 1; i < arr.length; i++) {
            currentNode.next = new NumNode(arr[i]);
            currentNode = currentNode.next;
        }
    }
    public at(index: number): NumNode {
        let currentNode = this.head;
        return this.atHelper(index, currentNode);
    }
    private atHelper(index: number, node: NumNode): NumNode {
        if (node === null) return null;
        if (index <= 0) return node;
        return this.atHelper(index - 1, node.next);
    }
    public printList(): void {
        console.log(this.printListHelper(this.head, ""));
    }
    private printListHelper(iterator: NumNode, str: string): string {
        if (iterator.next === null) return str + iterator.data;
        return this.printListHelper(iterator.next, str + iterator.data + " ");
    }
    public preappend(newNode: NumNode): void {
        newNode.next = this.head;
        this.head = newNode;
    }
    public append(newNode: NumNode): void {
        let iterator = this.scanning(this.head);
        iterator.next = newNode;
    }
    private scanning(iterator: NumNode): NumNode {
        if (iterator.next === null) return iterator;
        return this.scanning(iterator.next);
    }
    public popFront(): void {
        this.head = this.head.next;
    }
    public deleteNode(index: number): void {
        if (index === 0) return this.popFront();
        let targetNode = this.at(index - 1);
        if (targetNode === null) return null;
        targetNode.next = targetNode.next.next;
    }
    public reverse(): void {
        let reverse = this.head;
        this.head = this.head.next;
        reverse.next = null;
        while (this.head !== null) {
            let temp = this.head;
            this.head = this.head.next;
            temp.next = reverse;
            reverse = temp;
        }
        this.head = reverse;
    }
}

let numList = new SinglyLinkedList([35, 23, 546, 67, 86, 234, 56, 767, 34, 1, 98, 78, 555]);

numList.printList();
numList.reverse();
numList.printList();

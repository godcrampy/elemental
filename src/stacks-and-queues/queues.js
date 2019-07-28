class Node {
	constructor(data) {
		this.previous = null;
		this.data = data;
	}
}

class Queue {
	constructor() {
		this.first = null;
		this.last = null;
		this.size = 0;
	}
	queue(data) {
		let newNode = new Node(data);
		if (this.size === 0) {
			this.first = newNode;
		} else this.last.previous = newNode;
		this.size++;
		this.last = newNode;
		return this.size;
	}

	dequeue() {
		if (this.size == 0) return undefined;
		let temp = this.head;
		this.head = temp.previous;
		this.size--;
		return temp;
	}
}
class HashTable {
	constructor() {
		this.keyMap = new Array(79);
	}
	_hash(string) {
		let total = 0;
		const PRIME = 1327;
		for (let i = 0; i < Math.min(string.length, 100); i++) {
			total = (total * PRIME + string[i].charCodeAt(0)) % 79;
		}
		return total;
	}

	set(key, value) {
		let hash = this._hash(key);
		if (this.keyMap[hash] == undefined)
			this.keyMap[hash] = [
				[key, value]
			];
		else this.keyMap.push([key, value]);
	}

	get(key) {
		let hash = this._hash(key);
		let chain = this.keyMap[hash];
		for (let pair of chain)
			if (pair[0] === key) return pair[1];
		return undefined;
	}
	pairs() {
		let pairs = [];
		for (let i = 0; i < 79; i++)
			if (this.keyMap[i] != undefined)
				for (let pair of this.keyMap[i]) pairs.push(pair);
		return pairs;
	}
}
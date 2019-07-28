function linearSearch(array, target) {
	for (const index in array) {
		if (array[index] == target) return parseInt(index);
	}
	return -1;
}

function binarySearch(array, target) {
	// Set inital pointers
	let left = 0;
	let right = array.length;
	while (true) {
		let middle = Math.floor((left + right) / 2);
		if (array[middle] === target) return middle;
		if (array.length === 1) return -1;
		if (array[middle] < target) {
			// target belongs to the right;
			left = middle + 1;
		} else {
			// target belongs to the left
			right = middle - 1;
		}
	}
}

function stringSearch(string, target) {
	let counter = 0;
	let isSubstring = false;
	for (let i = 0; i < string.length; i++) {
		isSubstring = true;
		for (let j = 0; j < target.length; j++) {
			if (string[i + j] != target[j]) {
				isSubstring = false;
				break;
			}
		}
		if (isSubstring) counter++;
	}
	return counter;
}
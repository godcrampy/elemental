function bubbleSort(array) {
	let didDoSwapping = false;
	for (let i = 0; i < array.length; i++) {
		didDoSwapping = false;
		for (let j = array.length - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				[array[j], array[j - 1]] = [array[j - 1], array[j]];
				didDoSwapping = true;
			}
		}
		if (!didDoSwapping) break;
	}
}

function selectionSort(array) {
	let minPosition;
	for (let i = 0; i < array.length - 1; i++) {
		//i represents the position to swap with
		minPosition = i;
		for (let j = i + 1; j < array.length; j++)
			if (array[j] < array[minPosition])
				minPosition = j;
		[array[i], array[minPosition]] = [array[minPosition], array[i]];
	}
}

function insertionSort(array) {
	for (let i = 0; i < array.length - 1; i++)
		for (let j = i + 1; j > 0; j--)
			if (array[j] < array[j - 1])
				[array[j - 1], array[j]] = [array[j], array[j - 1]];
			else break;
}

function mergeSort(array) {
	if (array.length <= 1) return array;
	let midpoint = Math.floor(array.length / 2);
	let left = mergeSort(array.slice(0, midpoint));
	let right = mergeSort(array.slice(midpoint));
	return mergeArrays(left, right);
}

function mergeArrays(array1, array2) {
	// Given two functions, this function constructs a single sorted array
	let sortedArray = [],
		pointer1 = 0,
		pointer2 = 0;
	while (pointer1 != array1.length && pointer2 != array2.length)
		if (array1[pointer1] > array2[pointer2]) {
			sortedArray.push(array2[pointer2]);
			pointer2++;
		} else {
			sortedArray.push(array1[pointer1]);
			pointer1++;
		}
	if (pointer1 == array1.length)
		sortedArray = sortedArray.concat(array2.slice(pointer2));
	else
		sortedArray = sortedArray.concat(array1.slice(pointer1));
	return sortedArray;
}

function quickSort(array) {
	if (array.length <= 1) return array;
	let pivot = array[0];
	let pivotPosition = 0;
	for (let i = 1; i < array.length; i++)
		if (array[i] < pivot) {
			pivotPosition++;
			[array[pivotPosition], array[i]] = [array[i], array[pivotPosition]];
		}
	[array[0], array[pivotPosition]] = [array[pivotPosition], array[0]];
	let left = quickSort(array.slice(0, pivotPosition));
	let right = quickSort(array.slice(pivotPosition + 1));
	return [...left, pivot, ...right];
}

function getDigit(number, place) {
	// returns the number at the given place 124, 3 => 1
	return Math.floor(Math.abs(number) / Math.pow(10, place)) % 10;
}

function digitCount(number) {
	if (number == 0) return 1;
	return Math.floor(Math.log10(Math.abs(number))) + 1;
}

function mostDigits(array) {
	let digits = 0;
	for (let number of array)
		digits = Math.max(digitCount(number), number);
	return digits;
}

function radixSort(array) {
	let iterations = mostDigits(array);
	for (let i = 0; i < iterations; i++) {
		let bucket = Array.from({
			length: 10
		}, () => []);
		for (let number of array)
			bucket[getDigit(number, i)].push(number);
		array = [].concat(...bucket);
	}
	return array;
}
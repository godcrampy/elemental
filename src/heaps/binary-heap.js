class MaxBinaryHeap {
    constructor() {
        this.values = []
    }
    parentIndex(index) {
        if (index === 0) return 0;
        return Math.floor((index - 1) / 2)
    }
    parentValue(index) {
        return this.values[this.parentIndex(index)];
    }
    childIndexLeft(index) {
        let final = 2 * index + 1;
        if (final >= this.values.length) return index
        return final;
    }
    childIndexRight(index) {
        let final = 2 * index + 2;
        if (final >= this.values.length) return index
        return final;
    }
    childValueLeft(index) {
        return this.values[this.childIndexLeft(index)];
    }
    childValueRigth(index) {
        return this.values[this.childIndexRight(index)];
    }
    insert(value) {
        this.values.push(value)
        let currentIndex = this.values.length - 1;
        while (this.parentValue(currentIndex) < this.values[currentIndex]) {
            [this.values[currentIndex], this.values[this.parentIndex(currentIndex)]] = [this.values[this.parentIndex(currentIndex)], this.values[currentIndex]]
            currentIndex = this.parentIndex(currentIndex);
        }
    }
    remove(value) {
        let currentIndex = this.values.indexOf(value);
        // swap with the last
        [this.values[currentIndex], this.values[this.values.length - 1]] = [this.values[this.values.length - 1], this.values[currentIndex]];
        this.values.pop();
        while (this.values[currentIndex] < this.childValueLeft(currentIndex) || this.values[currentIndex] < this.childValueRigth(currentIndex)) {
            if (this.childValueLeft(currentIndex) > this.childValueRigth(currentIndex)) {
                //swap with left
                [this.values[currentIndex], this.values[this.childIndexLeft(currentIndex)]] = [this.values[this.childIndexLeft(currentIndex)], this.values[currentIndex]];
                currentIndex = this.childIndexLeft(currentIndex);
            } else {
                // swap with right guy
                [this.values[currentIndex], this.values[this.childIndexRight(currentIndex)]] = [this.values[this.childIndexRight(currentIndex)], this.values[currentIndex]];
                currentIndex = this.childIndexRight(currentIndex);
            }
        }
    }
}
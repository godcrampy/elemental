class Node {
    constructor(data) {
        this.left = null;
        this.right = null;
        this.data = data;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }
    insert(data) {
        let newNode = new Node(data)
        if (this.root === null) {
            this.root = newNode;
            return true;
        }
        let iterator = this.root;
        while (true) {
            if (data == iterator.data) return false;
            if (data > iterator.data) {
                // go to the right
                if (iterator.right == null) {
                    iterator.right = newNode;
                    break;
                }
                iterator = iterator.right;
            } else {
                // go to the left
                if (iterator.left == null) {
                    iterator.left = newNode;
                    break;
                }
                iterator = iterator.left;
            }
        }
        return true;
    }
    find(data) {
        let iterator = this.root;
        while (iterator != null) {
            if (data === iterator.data) return true;
            else if (data > iterator.data) iterator = iterator.right;
            else iterator = iterator.left;
        }
        return false;
    }
    BFS() {
        let queue = [];
        let list = [];
        queue.push(this.root);
        while (queue.length != 0) {
            let node = queue.shift();
            list.push(node.data);
            if (node.left != null) queue.push(node.left)
            if (node.right != null) queue.push(node.right)
        }
        return list
    }
    DFSPreOrder() {
        let list = [];

        function searchRecursive(node) {
            list.push(node.data);
            if (node.left != null) searchRecursive(node.left)
            if (node.right != null) searchRecursive(node.right)
        }
        searchRecursive(this.root);
        return list;
    }
    DFSPostOrder() {
        let list = [];

        function searchRecursive(node) {
            if (node.left != null) searchRecursive(node.left)
            if (node.right != null) searchRecursive(node.right)
            list.push(node.data);
        }
        searchRecursive(this.root);
        return list;
    }
    DFSInOrder() {
        let list = [];

        function searchRecursive(node) {
            if (node.left != null) searchRecursive(node.left)
            list.push(node.data);
            if (node.right != null) searchRecursive(node.right)
        }
        searchRecursive(this.root);
        return list;
    }
}
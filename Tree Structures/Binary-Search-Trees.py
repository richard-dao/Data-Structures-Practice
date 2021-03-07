# Python
class TreeNode(object):
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

class BinarySearchTree(object):
    def __init__(self, root = None):
        self.root = root

    def insert(self, current, value):
        if (self.root == None):
            self.root = TreeNode(value)
            return
        if (self.find(self.root, value, 0) != -1):
            return
        if (current.value < value):
            if (current.right == None):
                current.right = TreeNode(value)
                return
            return self.insert(current.right, value)
        if (current.value > value):
            if (current.left == None):
                current.left = TreeNode(value)
                return
            return self.insert(current.left, value)
        return

    def getRoot(self):
        return self.root

    def deleteNode(self, value):
        self.root = self.delete(self.root, value)

    def delete(self, current, value):
        if (current == None):
            return current
        elif(value > current.value):
            current.right = self.delete(current.right, value)
        elif(value < current.value):
            current.left = self.delete(current.left, value)
        else:
            if (current.left == None and current.right == None):
                current = None
            elif(current.left == None):
                current = current.right
            elif(current.right == None):
                current = current.left
            else:
                temp = self.findMin(current.right)
                current.value = temp.value
                current.right = self.delete(current.right, temp.value)
        return current

    def findMin(self, current):
        if (current.left == None):
            return current
        return self.findMin(current.left)

    def findMax(self, current):
        if (current.right == None):
            return current
        return self.findMax(current.right)

    def find(self, current, value, counter):
        if (self.root == None):
            return -1
        if (current == None):
            return -1
        if (current.value == value):
            return counter
        if (current.value > value):
            return self.find(current.left, value, counter+1)
        if (current.value < value):
            return self.find(current.right, value, counter+1)
        return -1

    def reverse(self, current):
        if (current == None):
            return
        temp = current.left
        self.reverse(current.left)
        current.left = current.right
        self.reverse(current.left)
        current.right = temp

    def printInOrder(self, current):
        if (current == None):
            return
        self.printInOrder(current.left)
        print(current.value, end = " ")
        self.printInOrder(current.right)

    def printPreOrder(self, current):
        if (current == None):
            return
        print(current.value, end = " ")
        self.printPreOrder(current.left)
        self.printPreOrder(current.right)

    def printPostOrder(self, current):
        if (current == None):
            return
        self.printPostOrder(current.left)
        self.printPostOrder(current.right)
        print(current.value, end = " ")

b = BinarySearchTree()
b.insert(b.getRoot(), 1)
b.insert(b.getRoot(), 3)
b.insert(b.getRoot(), -2)
b.insert(b.getRoot(), -3)
b.insert(b.getRoot(), -1)
b.insert(b.getRoot(), 4)
b.insert(b.getRoot(), 2)
b.insert(b.getRoot(), 0)
b.insert(b.getRoot(), -4)
b.insert(b.getRoot(), -5)

print(b.find(b.getRoot(), -5, 0))
b.printInOrder(b.getRoot())
print()
b.deleteNode(1)
print(b.getRoot().value)
b.printInOrder(b.getRoot())
b.reverse(b.getRoot())
print()
b.printInOrder(b.getRoot())

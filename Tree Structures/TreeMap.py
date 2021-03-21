class TreeMapNode(object):
    def __init__(self, key = None, value = None):
        self.left = None
        self.right = None
        self.dict = {}
        self.dict[key] = value
        self.key = key

class TreeMap(object):
    def __init__(self, root = None):
        self.root = root

    def getRoot(self):
        return self.root

    def insert(self, current, key, value):
        if (self.root == current):
            if (self.findLevel(self.root, key, 0) != -1):
                return
        if (self.root == None or current == None):
            self.root = TreeMapNode(key, value)
            return
        elif(key < current.key):
            if (current.left == None):
                current.left = TreeMapNode(key, value)
                return
            self.insert(current.left, key, value)
        elif(key > current.key):
            if (current.right == None):
                current.right = TreeMapNode(key, value)
                return
            self.insert(current.right, key, value)

    def deleteNode(self, key):
        self.root = self.delete(self.root, key)

    def delete(self, current, key):
        if (current == None):
            return current
        elif(key < current.key):
            current.left = self.delete(current.left, key)
        elif(key > current.key):
            current.right= self.delete(current.right, key)
        else:
            if (current.right == None and current.left == None):
                current = None
            elif(current.left == None):
                current = current.right
            elif(current.right == None):
                current = current.left
            else:
                temp = self.findMin(current.right)
                left = current.left
                right = current.right
                current = TreeMapNode(temp.key, temp.dict[temp.key])
                current.left = left
                current.right = right
                current.right = self.delete(current.right, temp.key)
        return current

    def findMin(self, current):
        if (current.left != None):
            return self.findMin(current.left)
        return current

    def findLevel(self, current, key, counter):
        if (self.root == None or current == None):
            return -1
        elif (key < current.key):
            return self.findLevel(current.left, key, counter+1)
        elif (key > current.key):
            return self.findLevel(current.right, key, counter+1)
        elif(key == current.key):
            return counter
        return -1

    def find(self, current, key):
        if (self.root == None or current == None):
            return -1
        elif (key < current.key):
            return self.find(current.left, key)
        elif (key > current.key):
            return self.find(current.right, key)
        elif(key == current.key):
            return current.dict[key]
        return -1

    def reverse(self, current):
        if (current != None):
            temp = current.right
            current.right = current.left
            current.left = temp

            self.reverse(current.left)
            self.reverse(current.right)

    def numberOfLeaves(self, current, counter):
        if (current == None):
            return counter
        if (current.left == None and current.right == None):
            return self.numberOfLeaves(current.left, counter+1)
        return self.numberOfLeaves(current.left, counter) + self.numberOfLeaves(current.right, counter)

    def print(self, input):
            if (input.lower() == "post order"):
                print("{", end="")
                self.printPostOrder(self.root)
                print("}")
            elif (input.lower() == "pre order"):
                print("{", end="")
                self.printPreOrder(self.root)
                print("}")
            else:
                print("{", end="")
                self.printInOrder(self.root)
                print("}")

    def printInOrder(self, current):
        if (current == None):
            return
        self.printInOrder(current.left)
        print("[" + current.key + " : " + str(current.dict[current.key]) + "]", end="")
        self.printInOrder(current.right)

    def printPreOrder(self, current):
        if (current == None):
            return
        print("[" + current.key + " : " + str(current.dict[current.key]) + "]", end="")
        self.printPreOrder(current.left)
        self.printPreOrder(current.right)

    def printPostOrder(self, current):
        if (current == None):
            return
        self.printPostOrder(current.left)
        self.printPostOrder(current.right)
        print("[" + current.key + " : " + str(current.dict[current.key]) + "]", end="")


t = TreeMap()
t.insert(t.getRoot(), "Hlavac", 735)
t.insert(t.getRoot(), "Dao", 984)
t.insert(t.getRoot(), "Strong", 145)
t.insert(t.getRoot(), "Dao", 510)
t.insert(t.getRoot(), "Bonet", 754)
t.print("in order")
t.deleteNode("Dao")
t.print("in order")
t.insert(t.getRoot(), "Dao", 510)
print(t.find(t.getRoot(), "Bonet"))
t.reverse(t.getRoot())
t.print("in order")
t.print("post order")
t.print("pre order")
print(t.numberOfLeaves(t.getRoot(), 0))

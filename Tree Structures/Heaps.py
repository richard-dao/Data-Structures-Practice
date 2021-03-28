import math
class HeapNode(object):
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

class MinHeap(object):
    def __init__(self, max, size = 0):
        self.maxSize = max
        self.size = size
        self.heap = list()
        self.heap = [None] * self.maxSize
    
    def getLeftChildIndex(self, parentIndex):
        return int((2 * parentIndex) + 1)
    
    def getRightChildIndex(self, parentIndex):
        return int((2 * parentIndex) + 1)
    
    def getParentIndex(self, childIndex):
        return int((childIndex - 1)/2)
    
    def hasLeftChild(self, index):
        if (self.getLeftChildIndex(index) > self.size):
            return False
        return True
    
    def hasRightChild(self, index):
        if (self.getRightChildIndex(index) > self.size):
            return False
        return True
    
    def hasParent(self, index):
        if (index > self.size or index == 0):
            return False
        return True
    
    def leftChild(self, index):
        return self.heap[self.getLeftChildIndex(index)]
    
    def rightChild(self, index):
        return self.heap[self.getRightChildIndex(index)]
    
    def parent(self, index):
        return self.heap[self.getParentIndex(index)]

    def expandArr(self):
        if (self.size == self.maxSize):
            temp = self.heap
            self.heap = [None] * (self.maxSize * 2)
            for x in range(0, len(temp)):
                self.heap[x] = temp[x]
            self.maxSize = self.maxSize * 2
        
    def isEmpty(self):
        return self.size == 0
    
    def peek(self):
        if (self.isEmpty()):
            return "Error"
        return self.heap[0]

    def poll(self):
        if (self.isEmpty()):
            return "Error"
        temp = self.heap[0]
        self.heap[0] = self.heap[self.size-1]
        self.size = self.size - 1
        self.heapifyDown()
        return temp
    
    def add(self, value):
        self.expandArr()
        self.heap[self.size] = value
        self.size = self.size + 1
        self.heapifyUp()

    def heapifyDown(self):
        i = 0
        while(self.hasLeftChild(i)):
            smallestIndex = self.getLeftChildIndex(i)
            if (self.hasRightChild(i) and (self.rightChild(i) < self.leftChild(i))):
                smallestIndex = self.getRightChildIndex(i)
            if (self.heap[i] < self.heap[smallestIndex]):
                return
            else:
                self.swap(i, smallestIndex)
            i = smallestIndex

    def heapifyUp(self):
        i = self.size - 1
        while (self.hasParent(i)):
            if (self.parent(i) > self.heap[i]):
                self.swap(self.getParentIndex(i), i)
            else:
                return
            i = self.getParentIndex(i)

    def swap(self, index1, index2):
        temp = self.heap[index1]
        self.heap[index1] = self.heap[index2]
        self.heap[index2] = temp

    def display(self):
        print("[", end="")
        for x in range(0, self.size):
            print(self.heap[x], end="")
            if (x != self.size - 1):
                print(", ", end="")
        print("]")

    def getHeap(self):
        rArr = list()
        for x in range(0, self.size):
            rArr.append(self.heap[x])
        return rArr

    def height(self):
        return 1 + int(math.log(self.size, 2))
class MinHeapTree(object):
    def __init__(self):
        self.root = None
    
    def convertArrToTree(self, heap, current, i):
        if (i < len(heap)):
            temp = HeapNode(heap[i])
            current = temp

            current.left = self.convertArrToTree(heap, current.left, 2 * i + 1)
            current.right = self.convertArrToTree(heap, current.right, 2 * i + 2)

        return current

    def printInOrder(self, current):
        if (current == None):
            return
        self.printInOrder(current.left)
        print(current.value, end=", ")
        self.printInOrder(current.right)
    
    def printLevelOrder(self, height):
        for x in range (0, height+1):
            self.printLevel(self.root, x)

    def printLevel(self, current, level):
        if (current == None):
            return
        if (level == 1):
            print(str(current.value), end= " ")
        elif(level > 1):
            self.printLevel(current.left, level - 1)
            self.printLevel(current.right, level - 1)
            
h = MinHeap(10)
h.add(0)
h.add(1)
h.add(2)
h.add(3)
h.add(4)
h.add(5)
h.add(6)
h.add(7)
h.poll()
h.display()
mT = MinHeapTree()
mT.root = mT.convertArrToTree(h.getHeap(), mT.root, 0)
mT.printLevelOrder(h.height())

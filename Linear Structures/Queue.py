# Queues as Linked Lists
class QueueNode(object):
    def __init__(self, value, next = None):
        self.value = value
        self.next = next

class Queue(object):
    def __init__(self, head = None, tail = None):
        self.head = head
        self.tail = tail

    def isEmpty(self):
        return self.head == None

    def peek(self):
        return self.head.value

    def push(self, value):
        newNode = QueueNode(value)
        if (self.isEmpty()):
            self.head = newNode
            self.tail = newNode
            return
        self.tail.next = newNode
        self.tail = newNode

    def pop(self):
        if (self.isEmpty()):
            return
        if (self.head.next == None):
            self.head = None
            self.tail = None
            return
        self.head = self.head.next

    def display(self):
        rArr = list()
        current = self.head
        while (current != None):
            rArr.append(current.value)
            current = current.next
        return rArr
def printS(arr):
    print()
    for x in range(0, len(arr)):
        print(arr[x], end= " ")
    print()

q = Queue()
print(q.isEmpty())
q.push(0)
q.push(1)
q.push(2)
q.push(3)
q.pop()
printS(q.display())
print(q.peek())



# Queues as Arrays
class Queue(object):
    def __init__(self, length, headIndex = 0, tailIndex = 0):
        self.queue = list()
        self.queue = [None] * length
        self.headIndex = headIndex
        self.tailIndex = tailIndex

    def isEmpty(self):
        return self.headIndex == self.tailIndex

    def peek(self):
        if (self.isEmpty()):
            return -1
        return self.queue[self.headIndex]

    def push(self, value):
        if (self.tailIndex > len(self.queue)-1):
             print("Queue Overflow")
             return
        self.queue[self.tailIndex] = value
        self.tailIndex = self.tailIndex + 1
        if (self.tailIndex > len(self.queue)):
            self.tailIndex = 0
        return

    def pop(self):
        if (self.isEmpty()):
            print("Queue Underflow")
            return
        self.headIndex = self.headIndex + 1
        if (self.headIndex > len(self.queue)):
            self.headIndex = 0

    def display(self):
        rArr = list()
        if (self.isEmpty()):
            return rArr
        if (self.tailIndex < self.headIndex):
            for x in range(self.headIndex, len(self.queue)):
                rArr.append(self.queue[x])
            for x in range(0, self.tailIndex):
                rArr.append(self.queue[x])
        else:
            for x in range(self.headIndex, self.tailIndex):
                rArr.append(self.queue[x])
        return rArr

def printS(arr):
    print()
    for x in range(0, len(arr)):
        print(arr[x], end= " ")
    print()

q = Queue(5)
print(q.isEmpty())
q.push(1)
q.pop()
q.push(2)
q.push(3)
q.push(4)
q.push(5)
printS(q.display())
print(q.peek())

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

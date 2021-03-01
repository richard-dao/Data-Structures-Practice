# Stacks as Linked List
class StackNode(object):
    def __init__(self, value, down = None):
        self.value = value
        self.down = down

class Stack(object):
    def __init__(self, top = None):
        self.top = top

    def isEmpty(self):
        return self.top == None

    def peek(self):
        return self.top.value

    def push(self, value):
        if (self.top == None):
            self.top = StackNode(value)
            return
        newNode = StackNode(value)
        newNode.down = self.top
        self.top = newNode

    def pop(self):
        if (self.top == None):
            return
        self.top = self.top.down

    def display(self):
        rArr = list()
        current = self.top
        while (current != None):
            rArr.append(current.value)
            current = current.down
        return rArr

def printS(arr):
    print()
    for x in range (0, len(arr)):
        print(arr[x], end= " ")
    print()

s = Stack()
print(s.isEmpty())
s.push(0)
s.push(1)
s.push(2)
s.push(3)
s.pop()
printS(s.display())
print(s.peek())


# Stacks as Arrays
class Stack(object):
    def __init__(self, length, topIndex = 0):
        self.stack = list()
        self.stack = [None] * length
        self.topIndex = topIndex

    def isEmpty(self):
        return self.topIndex == 0

    def peek(self):
        if (self.isEmpty()):
            return -1
        return self.stack[self.topIndex-1]

    def push(self, value):
        if (self.topIndex > len(self.stack)-1):
            return
        self.stack[self.topIndex] = value
        self.topIndex = self.topIndex + 1
        return

    def pop(self):
        if (self.isEmpty()):
            return
        self.topIndex = self.topIndex - 1

    def display(self):
        if (self.topIndex == 0):
            return
        rArr = [None] * self.topIndex
        counter = 0
        for x in range(self.topIndex-1, -1, -1):
            rArr[counter] = self.stack[x]
            counter = counter + 1
        return rArr

def printS(arr):
    print()
    for x in range(0, len(arr)):
        print(arr[x], end= " ")
    print()


s = Stack(5)
print(s.isEmpty())
s.push(0)
s.push(1)
s.push(2)
s.push(3)
s.pop()
printS(s.display())
print(s.peek())

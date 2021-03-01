class DoublyCircularlyNode(object):
    def __init__(self, value, next = None, prev = None):
        self.value = value
        self.next = next
        self.prev = prev

class DoublyCircularlyLinkedList(object):
    def __init__(self, last = None):
        self.last = last

    def getValues(self):
        rArr = list()
        if (self.last == None):
          return rArr
        current = self.last
        for x in range(0, self.getLength()):
          rArr.append(current.next.value)
          current = current.next
        rArr[self.getLength()-1] = self.last.value
        return rArr

    def getLength(self):
        counter = 0
        current = self.last
        if (self.last == None):
            return 0
        while (current.next != self.last):
            counter = counter + 1
            current = current.next
        return counter + 1

    def append(self, value):
        newNode = DoublyCircularlyNode(value)
        if (self.last == None):
            self.last = newNode
            self.last.prev = self.last
            self.last.next = self.last
            return
        newNode.prev = self.last
        newNode.next = self.last.next
        self.last.next.prev = newNode
        self.last.next = newNode
        self.last = newNode

    def prepend(self, value):
        newNode = DoublyCircularlyNode(value)
        if (self.last == None):
            self.append(value)
            return
        newNode.prev = self.last
        newNode.next = self.last.next
        self.last.next.prev = newNode
        self.last.next = newNode

    def insert(self, value, position):
        if (self.last == None or position == 0):
            self.prepend(value)
            return

        if (position > self.getLength()-1):
            self.append(value)
            return
        current = self.last.next
        newNode = DoublyCircularlyNode(value)
        counter = 0
        while (counter + 1 < position and current.next != self.last):
            current = current.next
            counter = counter + 1
        newNode.prev = current
        newNode.next = current.next
        current.next.prev = newNode
        current.next = newNode

    def deleteFirst(self, value):
        if (self.last == None):
            return
        if (self.last.next == self.last and self.last.value == value):
            self.last = None
            return
        current = self.last
        while (current.next.value != value and current.next != self.last):
            current = current.next
        if (current.next == self.last and self.last.value == value):
            self.last.prev.next = self.last.next
            self.last.next.prev = self.last.prev
            self.last = self.last.prev
            return
        elif(current.next == self.last):
            return
        else:
            current.next = current.next.next
            current.next.prev = current

    def deleteAll(self, value):
        if (self.last == None):
            return
        current = self.last.next
        while(current != self.last):
            if (current.value == value):
                self.deleteFirst(value)
            current = current.next
        self.deleteFirst(value)

    def deleteAt(self, position):
        if (self.last == None or position > self.getLength()-1):
            return
        if (self.last.next == self.last):
            if(position == 0):
                last = None
                return

        current = self.last
        counter = 0
        while (current.next != self.last and counter < position):
            current = current.next
            counter = counter + 1
        if (current.next == self.last):
            self.last.prev.next = self.last.next
            self.last.next.prev = self.last.prev
            self.last = self.last.prev
            return
        current.next = current.next.next
        current.next.prev = current

    def reverse(self):
        if (self.last == None):
            return

        previous = self.last
        current = self.last.next
        nxt = None

        while (current != self.last):
            nxt = current.next
            current.next = previous
            current.prev = nxt
            previous = current
            current = nxt
        nxt = current.next
        current.next = previous
        current.prev = nxt
        self.last = nxt

    def setLast(self, newLast):
        self.last = newLast

    def getLast(self):
        return self.last

    def reverseRecursive(self, previous, current, stop):
        nxt = None
        if (current == stop):
            nxt = current.next
            current.next = previous
            current.prev = nxt
            return nxt
        nxt = current.next
        current.next = previous
        current.prev = nxt
        return self.reverseRecursive(current, nxt, stop)

def printL(dcll):
  for x in range(0, len(dcll)):
    print(dcll[x], end = " ")
l = DoublyCircularlyLinkedList()

l.append(0)
l.insert(2, 2)
l.insert(3, 4)
l.append(1)
l.append(1)
l.append(1)
l.prepend(-1)
l.deleteAll(1)
l.deleteAt(1)
l.reverse()
l.setLast(l.reverseRecursive(l.getLast(), l.getLast().next, l.getLast()))

printL(l.getValues())




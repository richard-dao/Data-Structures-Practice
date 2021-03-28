class PriorityNode(object):
    def __init__(self, value, level):
        self.value = value
        self.level = level
        self.next = None

class PriorityQueue(object):
    def __init__(self):
        self.head = None
    
    def isEmpty(self):
        return self.head == None
    
    def peek(self):
        if (self.isEmpty()):
            return "Empty"
        current = self.head
        minNode = self.head
        while (current != None):
            if (current.level < minNode.level):
                minNode = current
            current = current.next
        return minNode.value

    def enqueue(self, value, level):
        if (self.isEmpty()):
            self.head = PriorityNode(value, level)
            return
        current = self.head
        while (current.next != None):
            current = current.next
        current.next = PriorityNode(value, level)

    def dequeue(self):
        current = self.head
        minNode = self.head
        prev = None
        prevMin = None
        if (self.isEmpty()):
            return "Empty"
        while (current != None):
            if (current.level < minNode.level):
                minNode = current
                prevMin = prev
            prev = current
            current = current.next
        if (minNode == self.head):
            head = head.next
            if (head == None):
                return "Empty"
            return head.value
        value = minNode.value
        prevMin.next = prevMin.next.next
        return value

    def display(self):
        current = self.head
        while (current != None):
            print("[" + str(current.value) + " : " + str(current.level) + "]")
            current = current.next

p = PriorityQueue()
p.enqueue(9, 4)
p.enqueue(10, 3)
p.enqueue(13, 5)
p.enqueue(10, 2)
p.enqueue(8, 2)
print(p.peek())
p.dequeue()
print(p.peek())
p.display()

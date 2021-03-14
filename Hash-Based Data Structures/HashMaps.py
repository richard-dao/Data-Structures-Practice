# Python
class Node(object):
    def __init__(self, next=None, key=None, value=None):
        self.next = next
        self.key = key
        self.value = value

class LinkedListMap(object):

    def __init__(self, head = None):
        self.head = head

    def prepend(self, key, value):
        if (self.head == None):
            self.head = Node(None, key, value)
            return
        tempHead = self.head
        self.head = Node(None, key, value)
        self.head.next = tempHead

    def delete(self, key):
        if (self.head == None):
            return
        if (self.head.key == key):
            self.head = self.head.next
            return
        current = self.head
        while (current != None and current.next != key):
            current = current.next
        current.next = current.next.next

    def findValue(self, key):
        current = self.head
        while (current != None and current.key != key):
            current = current.next
        if (current == None):
            return -1
        return current.value

    def print(self):
        current = self.head
        if (current == None):
            return
        print("{", end = "")
        while(current != None):
            print("[" + current.key + " : " + str(current.value) + "]", end="")
            current = current.next
        print("}")

    def getHead(self):
        if (self.head == None):
            return None
        return self.head

class HashMap(object):
    def __init__(self, size = 0):
        self.hashmap = list()
        self.hashmap = [None] * size;
        self.size = size

    def hash(self, str):
        hash = 0
        leftShiftValue = 1

        for x in range(0, 2):
            if (len(str) > x):
                hash = ord(str[x]) + ((hash << leftShiftValue) - hash)
        return hash

    def add(self, key, value):
        index = self.hash(key)
        if (self.hashmap[index] == None):
            self.hashmap[index] = LinkedListMap()
        if (self.hashmap[index].findValue(key) != -1):
            return
        self.hashmap[index].prepend(key, value)

    def delete(self, key):
        index = self.hash(key)
        if (self.hashmap[index] == None):
            return
        self.hashmap[index].delete(key)

    def get(self, key):
        index = self.hash(key)
        return self.hashmap[index].findValue(key)

    def print(self):
        for x in range(0, self.size):
            if (self.hashmap[x] != None):
                self.hashmap[x].print()


h = HashMap(253)
h.add("Hlavac", 735)
h.add("Strong", 145)
h.add("Dao", 984)
h.add("Dao", 118)
h.add("Dang", 567)
print(h.get("Dao"))
h.print()
h.delete("Strong")
h.delete("Strong")
h.print()
h.add("A", 123)
h.add("", 456)
h.add("%", 789)
h.add("~~", 5)
h.print()


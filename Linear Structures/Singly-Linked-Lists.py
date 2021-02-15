class Node(object):
  def __init__(self, value, next = None):
    self.value = value
    self.next = next
  def getValue(self):
    return self.value
  def getNext(self):
    return self.next
  def setNext(self, next):
    self.next = next

class LinkedList(object):
  def __init__(self, head = None):
    self.head = head
      
  def getValues(self):
    current = self.head
    llList = list()
    while (current != None):
      llList.append(current.getValue())
      current = current.next
    return llList
    
  def getHead(self):
    return self.head
    
  def setHead(self, head):
    self.head = head
    
  def append(self, value):
    current = self.head
    if (self.head == None):
      self.head = Node(value)
    else:
      while (current.next != None):
        current = current.next
      current.next = Node(value)
      
  def insert(self, value, position):
    current = self.head
    counter = 0
    if (self.head == None):
      append(value)
      return
    if (position > self.getLength()-1):
      append(value)
      return
    if (position == counter):
      prepend(value)
      return
    while (counter + 1 < position):
      current = current.next
      counter = counter + 1
    newNode = Node(value)
    nxt = current.next
    current.next = newNode
    newNode.next = nxt
  
  def prepend(self, value):
    newHead = Node(value)
    newHead.setNext(self.head)
    self.head = newHead
  
  def deleteFirst(self, value):
    if (self.head == None):
      return
    if (self.head.getValue() == value):
      self.head = self.head.next
      return
    current = self.head
    while (current.next != None):
      if (current.next.getValue() == value):
        current.next = current.next.next
        return
      current = current.next
  
  def deleteAll(self, value):
    if(self.head == None):
      return
    current = self.head
    while (current.next != None):
      if (current.next.getValue() == value):
        current.next = current.next.next
      else:
        current = current.next
    if (self.head.getValue() == value):
      self.head = self.head.next
  
  def deleteAt(self, position):
    current = self.head
    counter = 0
    if (self.head == None or position >= self.getLength()):
      return
    if (position == counter):
      self.head = self.head.next
      return
    while (counter + 1 < position):
      current = current.next
      counter = counter + 1
    current.next = current.next.next
    
  def getLength(self):
    current = self.head
    count = 0
    if (self.head == None):
      return 0
    while (current != None):
      count = count + 1
      current = current.next
    return count
    
  def reverse(self):
    previous = None
    current = self.head
    nxt = 0
    if (self.head == None):
      return
    while (current != None):
      nxt = current.next
      current.next = previous
      previous = current
      current = nxt
    self.head = previous
    
  def reverseRecursive(self, current, previous):
      if (current == None):
        return previous
      nxt = current.next
      current.next = previous
      return self.reverseRecursive(nxt, current)
    
l = LinkedList()
l.append(1)
l.append(2)
l.prepend(3)
l.append(1)
l.deleteAt(3)
l.setHead(l.reverseRecursive(l.getHead(), None))
l.insert(9, 1)
print(l.getValues())
    

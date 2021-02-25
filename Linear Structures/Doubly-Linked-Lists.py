class DoublyNode(object):
  def __init__(self, value, next = None, prev = None):
    self.value = value;
    self.next = next;
    self.prev = prev;
  def getValue(self):
    return self.value
  def getNext(self):
    return self.next
  def getPrev(self):
    return self.prev
  def setNext(self, next):
    self.next = next
  def setPrev(self, prev):
    self.prev = prev
    
class DoublyLinkedList(object):
  def __init__(self, head = None):
    self.head = head
    
  def getHead(self):
    return self.head
    
  def setHead(self, head):
    self.head = head
    
  def getTail(self):
    current = self.head
    if (self.head == None):
      return self.head
    while (current.next != None):
      current = current.next
    return current
    
  def append(self, value):
    current = self.head
    if (current == None):
      self.head = DoublyNode(value)
      return
    while (current.next != None):
      current = current.next
    current.next = DoublyNode(value)
    current.next.prev = current
    
  def prepend(self, value):
    current = self.head
    if (current == None):
      self.head = DoublyNode(value)
      return
    newHead = DoublyNode(value)
    newHead.next = self.head
    self.head.prev = newHead
    self.head = newHead
    
  def insert(self, value, position):
    current = self.head
    if (self.head == None):
      prepend(value)
      return
    if (position == 0):
      prepend(value)
      return
    count = 0
    while (count + 1 < position):
      current = current.next
      count = count + 1
    if (current.next == None):
      append(value)
      return
    inserted = DoublyNode(value)
    nextTemp = current.next
    current.next = inserted
    inserted.prev = nextTemp
    inserted.next = nextTemp
    nextTemp.prev = inserted
    
  def deleteFirst(self, value):
    current = self.head
    if (self.head == None):
      return
    if (self.head.value == value):
      self.head = current.next
      self.head.prev = None
      return
    while (current.value != value and current != None):
      current = current.next
    if (current != None and current.next != None):
      current.prev.next = current.next
      current.next.prev = current.prev
    elif(current != None):
      current.prev.next = current.next
    else:
      return
    return
    
  def deleteAt(self, position):
    current = self.head
    if (self.head == None):
      return
    if (position == 0 and self.head.next != None):
      newHead = self.head.next
      self.head = newHead
      self.head.prev = None
      return
    elif(position == 0):
      self.head = None
      return
    counter = 0
    while (counter + 1 < position and current != None):
      current = current.next
      counter = counter + 1
    
    if (current == None):
      return
    elif(current.next == None):
      current.next = None
    elif(current.next.next == None):
      current.next = None
    else:
      current.next = current.next.next
    return
  
  def deleteAll(self, value):
    current = self.head
    if (self.head == None):
      return
    while (current != None):
      if (self.head.value == value and self.head.next != None):
        self.head = self.head.next
        self.head.prev = None
      elif(self.head.value == value):
        self.head = None
        return
      elif(current.value == value and current.next != None):
        current.prev.next = current.next
        current.next.prev = current.prev
      elif (current.value == value):
        current.prev.next = None
      current = current.next
  
  def getLength(self):
    counter = 0
    current = self.head
    while (current != None):
      current = current.next
      counter = counter + 1
    return counter
  
  def getValues(self):
    rArr = list()
    current = self.head
    while(current != None):
      rArr.append(current.value)
      current = current.next
    return rArr
  
  def reverseRecursive(self, current):
    if (current.next == None):
      current.next = current.prev
      current.prev = None
      return current
    tempNext = current.next
    current.next = current.prev
    current.prev = tempNext
    return self.reverseRecursive(tempNext)
  
  def reverse(self):
    current = self.head
    tempNext = None
    
    if (self.head == None):
      return
    while (current != None):
      if (current.next == None):
        current.next = current.prev
        current.prev = None
        self.head = current
        return
      tempNext = current.next
      current.next = current.prev
      current.prev = tempNext
      current = tempNext
    self.head = current
    
  
def printOutLL(list):
  for x in range (0, l.getLength()):
    print(list[x], end = " ")
  print()
    
l = DoublyLinkedList()
l.prepend(1)
l.prepend(0)
l.append(2)
l.append(1)
l.append(2)
printOutLL(l.getValues())
l.insert(4,3)
printOutLL(l.getValues())
l.deleteFirst(2)
l.append(3)
l.deleteAt(4)
l.append(1)
l.append(1)
l.deleteAll(1)
printOutLL(l.getValues())
l.reverse()
printOutLL(l.getValues())
l.setHead(l.reverseRecursive(l.getHead()))
printOutLL(l.getValues())


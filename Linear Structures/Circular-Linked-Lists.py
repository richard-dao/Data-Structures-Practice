class CircularlyNode(object):
  def __init__(self, value, next = None):
    self.value = value
    self.next = next
  
class CircularlyLinkedList(object):
  def __init__(self, last = None):
    self.last = last
  
  def getLength(self):
    current = self.last
    if (self.last == None):
      return 0
    counter = 0
    while (current.next != self.last):
      counter = counter + 1
      current = current.next
    return counter + 1
    
  def append(self, value):
    newNode = CircularlyNode(value)
    if (self.last == None):
      self.last = newNode
      self.last.next = self.last
      return
    newNode.next = self.last.next
    self.last.next = newNode
    self.last = newNode
  
  def prepend(self, value):
    newNode = CircularlyNode(value)
    if (self.last == None):
      self.last = newNode
      self.last.next = self.last
      return
    newNode.next = self.last.next
    self.last.next = newNode
    
  def insert(self, value, position):
    current = self.last.next
    newNode = CircularlyNode(value)
    counter = 0
    if (self.last == None or position == 0):
      append(value)
      return
    if (position > self.getLength()-1):
      append(value)
      return
    while (current.next != self.last and counter + 1 < position):
      current = current.next
      counter = counter + 1
    newNode.next = current.next
    current.next = newNode
    
  def deleteFirst(self, value):
    current = self.last
    if (self.last == None):
      return
    while(current.next != self.last and current.next.value != value):
      current = current.next
    if (current.next.value != value):
      return
    elif(current.next != self.last):
      current.next = current.next.next
    else:
      tempCurrent = self.last
      if (self.last.value == value):
        if (self.last.next == self.last):
          self.last = None
          return
        while (tempCurrent.next != self.last):
          tempCurrent = tempCurrent.next
        tempCurrent.next = tempCurrent.next.next
        self.last = tempCurrent
        return
  
  def deleteAll(self, value):
    current = self.last.next
    if (self.last == None):
      return
    counter = 0
    while (current.next != self.last):
      if (current.value == value):
        counter = counter + 1
      current = current.next
    if (self.last.value == value):
      counter = counter + 1
    
    for x in range (0, counter+1):
      self.deleteFirst(value)
      
  def deleteAt(self, position):
    if (self.last == None or position > self.getLength()-1):
      return
    if (self.last.next == self.last):
      if (position == 0):
        self.last = None
        return
    current = self.last
    counter = 0
    while (current.next != self.last and counter < position):
      current = current.next
      counter = counter + 1
    if (position == self.getLength()-1):
      current.next = self.last.next
      self.last = current
      return
    current.next = current.next.next
  
  def getValues(self):
    rArr = list()
    current = self.last
    if (self.last == None):
      return rArr
    for x in range(0, self.getLength()):
      current = current.next
      rArr.append(current.value)
    return rArr
    
  def reverse(self):
    prev = self.last
    current = self.last.next
    nxt = None
    while(current != self.last):
      nxt = current.next
      current.next = prev
      prev = current
      current = nxt
    nxt = current.next
    current.next = prev
    prev = current
    self.last = nxt
  
  def getPrev(self):
    current = self.last
    while(current.next != self.last):
      current = current.next
    return current
  
  def reverseRecursive(self, current, previous, stop):
    nxt = None
    if (current.next == stop):
      nxt = current.next
      current.next = previous
      return nxt
    nxt = current.next
    current.next = previous
    return self.reverseRecursive(nxt, current, stop)
    
  def getLast(self):
    return self.last
    
  def setLast(self, value):
    self.last = value
    
def printL(l):
  for x in range(0, len(l)):
    print(l[x], end = " ")
  print()

l = CircularlyLinkedList()
l.append(0);
l.append(1);
l.append(2);
l.append(3);
l.append(3);
printL(l.getValues())
l.prepend(-1);
l.insert(9, 5);
l.append(3);
l.deleteFirst(3);
l.append(3);
l.append(3);
l.deleteAll(3);
		
printL(l.getValues());
l.deleteAt(4);
printL(l.getValues());
l.reverse();
printL(l.getValues());
l.setLast(l.reverseRecursive(l.getLast().next, l.getLast(), l.getLast().next));
printL(l.getValues());

    
    

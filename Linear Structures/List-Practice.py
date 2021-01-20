# Python

# 1. Return Combined List
# ['a', 'b', 'c'], [1, 2, 3] -> [('a', 1), ('b', 2), ('c', 3)]
# [1, 2], [] -> [(1, None), (2, None)]
# [1], ['a', 'b'] -> [(1, 'a'), (None, 'b')]

def ziplist(l1, l2):
    
    # YOUR CODE HERE
    max = 0
    outputList = list()
    if (len(l1) > len(l2)):
      max = len(l1)
      for x in range(0, max-len(l2)):
        l2.append(None)
    if (len(l2) > len(l1)):
      max = len(l2)
      for x in range(0, max-len(l1)):
        l1.append(None)
    else:
      max = len(l1)
    for x in range(0, max):
      var = (l1[x], l2[x])
      outputList.append(var)
    return outputList
    raise NotImplementedError()
    
# 2. Return Set of Elements That Occur 3 or More Times
# [1, 3, 5, 4, 3, 7, 6, 3, 7, 7, 7, 1, 2, 0, 3, 1] -> {1, 3, 7}
# [] -> set()

def threeormore(l):
    # YOUR CODE HERE
    l.sort()
    outputList = list()
    for number in l:
      count = 0
      for x in l:
        if x == number:
          count = count + 1
        else:
          count = count
      if count >= 3:
        outputList.append(number)
    final = set()
    for x in outputList:
      if x not in final:
        final.add(x)
    return final
    raise NotImplementedError()

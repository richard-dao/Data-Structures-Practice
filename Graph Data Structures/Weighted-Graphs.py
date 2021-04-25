class PriorityQueue(object):
    def __init__(self):
        self.queue = list()
    
    def add(self, Edge):
        self.queue.append(Edge)
        for i in range(0, len(self.queue)):
                already_sorted = True
                for j in range(len(self.queue) - i - 1):
                    if (self.queue[j].weight > self.queue[j+1].weight):
                        self.queue[j], self.queue[j+1] = self.queue[j+1], self.queue[j]
                    already_sorted = False
                if already_sorted:
                    break
    def pop(self):
        return self.queue.pop(0)
    
    def isEmpty(self):
        return not self.queue

class Edge(object):
    def __init__(self, source, connection, weight):
        self.source = source
        self.connection = connection
        self.weight = weight

class WeightedGraph(object):
    def __init__(self, V):
        self.V = V
        self.adj = list()
        for i in range(0, self.V):
            x = list()
            self.adj.append(x)
    
    def addEdge(self, v, w, weight):
        self.adj[v].append(Edge(v, w, weight))
        self.adj[w].append(Edge(w, v, weight))
    
    def returnAdjacent(self, v):
        return self.adj[v]
    
    def printG(self):
        for i in range(0, self.V):
            print(str(i), end=" | ")
            for j in range(0, len(self.adj[i])):
                print(str(self.adj[i][j].connection) + " = " + str(self.adj[i][j].weight), end=", ")
            print()
    def getV(self):
        return self.V

class Dijkstra(object):
    def __init__(self, graph, s):
        self.s = s
        self.pq = PriorityQueue()
        self.edgeTo = list()
        self.edgeTo = [None] * graph.getV()
        self.distTo = list()
        self.distTo = [9999] * graph.getV()
        self.marked = list()
        for i in range (0, graph.getV()):
            if (i != self.s):
                self.distTo[i] = 9999
        self.distTo[s] = 0
        self.pq.add(Edge(s, s, 0))
        self.dijkstra(graph, s)
    
    def dijkstra(self, graph, v):
        while (self.pq.isEmpty() == False):
            n = self.pq.pop()
            self.marked.append(n.connection)
            for i in graph.returnAdjacent(n.connection):
                if (i.connection not in self.marked):
                    if (self.distTo[n.connection] + i.weight < self.distTo[i.connection]):
                        self.distTo[i.connection] = self.distTo[n.connection] + i.weight
                        self.edgeTo[i.connection] = n.connection
                        self.pq.add(Edge(n.connection, i.connection, self.distTo[i.connection]))
    
    def pathTo(self, t):
        path = list()
        if (self.hasPathTo(t) == False):
            return path
        i = t
        while (i != self.s):
            path.append(i)
            i = self.edgeTo[i]
        path.append(self.s)
        return path[::-1]

        
    def hasPathTo(self, t):
        if (t in self.marked):
            return True
        return False
    
    def getDistTo(self):
        return self.distTo
    
    def getMarked(self):
        return self.marked
    
    def getEdgeTo(self):
        return self.edgeTo

class WeightedQuickUnion(object):
    def __init__(self, size):
        self.sets = list()
        for i in range (0, size):
            self.sets.append(-1)
    
    def root(self, current):
        i = current
        while (self.sets[i] != -1):
            i = self.sets[i]
        return i
    
    def isConnected(self, s, t):
        return self.root(s) == self.root(t)
    
    def connect(self, s, t):
        self.sets[self.root(s)] = self.root(t)

class Kruskal(object):
    def __init__(self, graph):
        self.pq = PriorityQueue()
        self.mst = list()
        for i in range(0, graph.getV()):
            for j in graph.returnAdjacent(i):
                self.pq.add(j)
        
        self.kruskal(graph)

    def kruskal(self, graph):
        wqu = WeightedQuickUnion(graph.getV())
        while (self.pq.isEmpty() == False):
            n = self.pq.pop()
            if (wqu.isConnected(n.source, n.connection) == False):
                wqu.connect(n.source, n.connection)
                self.mst.append(n)
    
    def returnMST(self):
        return self.mst

wg = WeightedGraph(11)
wg.addEdge(0, 1, 1)
wg.addEdge(1, 2, 2)
wg.addEdge(1, 4, 3)
wg.addEdge(2, 5, 4)
wg.addEdge(3, 4, 5)
wg.addEdge(4, 5, 6)
wg.addEdge(5, 6, 7)
wg.addEdge(5, 8, 8)
wg.addEdge(6, 7, 9)
wg.printG()
print("---")
start = 0
end = 7
d = Dijkstra(wg, start)

print("Shortest Path From " + str(start) + " to " + str(end) + ": ")

for i in range(0, len(d.pathTo(end))):
    if (i == len(d.pathTo(end))-1):
        print(d.pathTo(end)[i])
    else:
        print(d.pathTo(end)[i], end=" => ")
l = d.getDistTo()
print("Total Weight: " + str(l[end]))
print("---")



k = Kruskal(wg)
print("MST: ")
for i in k.returnMST():
    print(str(i.source) + " <=> " + str(i.connection) + ": " + str(i.weight))


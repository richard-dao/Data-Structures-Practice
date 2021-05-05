class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = list()
        for x in range (0, V):
            self.adj.append(list())
    
    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

    def returnAdj(self, v):
        return self.adj[v]
    
    def print(self):
        for x in range (0, self.V):
            for y in range (0, len(self.adj[x])):
                print(str(x) + "-" + str(self.adj[x][y]), end=" ")
            print()
    
class DFS(object):
    def __init__(self, graph, s):
        self.s = s
        self.marked = [False] * graph.V
        self.edgeTo = [None] * graph.V
        self.dfs(graph, s)
        
    def dfs(self, graph, v):
        self.marked[v] = True
        for x in graph.returnAdj(v):
            if (self.marked[x] != True):
                self.edgeTo[x] = v
                self.dfs(graph, x)
        
    def pathTo(self, t):
        if (self.hasPathTo(t) == False):
            return None
        path = list()
        i = t;
        while (i != self.s):
            path.append(i)
            i = self.edgeTo[i]
        path.append(self.s)
        return path[::-1]

    def hasPathTo(self, t):
        return self.marked[t]

g = Graph(9)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(1, 4)
g.addEdge(2, 5)
g.addEdge(3, 4)
g.addEdge(4, 5)
g.addEdge(5, 6)
g.addEdge(5, 8)
g.addEdge(6, 7)
g.print();
d = DFS(g, 0)
p = d.pathTo(7)
for x in p:
    print(x, end=" ")
print(d.hasPathTo(9))

//UnWeightedGraphs.hpp
#include <iostream>
#include <vector>
using namespace std;
class UnWeightedGraphs{
    public:
        int V;
        std::vector<std::vector<int>> adj;
        UnWeightedGraphs(int vertices);
        void addEdge(int v, int w);
        std::vector<int> returnAdjacent(int v);
        void printG();
};

//UnWeightedGraphs.cpp
#include "UnweightedGraphs.hpp"
#include <iostream>
#include <vector>
using namespace std;

UnWeightedGraphs::UnWeightedGraphs(int vertices){
    V = vertices;
    std::vector<std::vector<int>> temp(vertices);
    adj = temp;
    for (int i = 0; i < V; i++){
        std::vector<int> neighbors;
        adj[i] = neighbors;
    }

}

void UnWeightedGraphs::addEdge(int v, int w){
    adj[w].push_back(v);
    adj[v].push_back(w);
}

std::vector<int> UnWeightedGraphs::returnAdjacent(int v){
    return adj[v];
}

void UnWeightedGraphs::printG(){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < adj[i].size(); j++){
            std::cout << i << "-" << adj[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//DFS.hpp
#include "UnWeightedGraphs.cpp"
#include <iostream>
#include <vector>
using namespace std;

class DFS{
    public:
        std::vector<bool> marked;
        std::vector<int> edgeTo;
        int s;
        DFS(UnWeightedGraphs graphs, int S);
        void dfs(UnWeightedGraphs graphs, int v);
        std::vector<int> pathTo(int t);
        bool hasPathTo(int t);
        std::vector<bool> getMarked();
        std::vector<int> getEdgeTo();
};

//DFS.cpp
#include "DFS.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

DFS::DFS(UnWeightedGraphs graphs, int S){
    s = S;
    std::vector<bool> tempMarked(graphs.V);
    std::vector<int> tempEdgeTo(graphs.V);
    marked = tempMarked;
    edgeTo = tempEdgeTo;
    dfs(graphs, s);
}

void DFS::dfs(UnWeightedGraphs graphs, int v){
    marked[v] = true;
    std::vector<int> neighbors = graphs.returnAdjacent(v);
    for (int i : neighbors){
        if (marked[i] != true){
            edgeTo[i] = v;
            dfs(graphs, i);
        }
    }
}

std::vector<int> DFS::pathTo(int t){
    std::vector<int> path;
    if (hasPathTo(t) == false){
        return path;
    }
    for (int i = t; i != s; i = edgeTo[i]){
        path.push_back(i);
    }
    path.push_back(s);
    std::reverse(path.begin(), path.end());
    return path;
}

bool DFS::hasPathTo(int t){
    return marked[t];
}

std::vector<bool> DFS::getMarked(){
    return marked;
}

std::vector<int> DFS::getEdgeTo(){
    return edgeTo;
}

//BFS.hpp
#include "DFS.cpp"
#include <iostream>
#include <vector>
using namespace std;

class BFS{
    public:
        std::vector<bool> marked;
        std::vector<int> edgeTo;
        int s;
        BFS(UnWeightedGraphs graphs, int S);
        void bfs(UnWeightedGraphs graphs, int v);
        std::vector<int> shortestPath(int t);
        bool hasPathTo(int t);
        std::vector<bool> getMarked();
        std::vector<int> getEdgeTo();
};

//BFS.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "BFS.hpp"
using namespace std;

BFS::BFS(UnWeightedGraphs graph, int S){
    s = S;
    std::vector<bool> tempMarked(graph.V);
    std::vector<int> tempEdgeTo(graph.V);
    marked = tempMarked;
    edgeTo = tempEdgeTo;
    bfs(graph, s);
}

void BFS::bfs(UnWeightedGraphs graph, int v){
    queue<int> q;
    marked[s] = true;
    q.push(s);

    while (!q.empty()){
        int n = q.front();
        q.pop();
        std::vector<int> adj = graph.returnAdjacent(n);
        for (int i : adj){
            if (!marked[i]){
                q.push(i);
                marked[i] = true;
                edgeTo[i] = n;
            }
        }
    }
}

std::vector<int> BFS::shortestPath(int t){
    std::vector<int> path;
    if (hasPathTo(t) == false){
        return path;
    }
    for (int i = t; i != s; i = edgeTo[i]){
        path.push_back(i);
    }
    path.push_back(s);
    std::reverse(path.begin(), path.end());
    return path;
}

bool BFS::hasPathTo(int t){
    return marked[t];
}

std::vector<bool> BFS::getMarked(){
    return marked;
}

std::vector<int> BFS::getEdgeTo(){
    return edgeTo;
}

//main.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "BFS.cpp"

int main(){
    UnWeightedGraphs g = UnWeightedGraphs(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.printG();
    std::cout << "---\n";
    DFS d = DFS(g, 2);
    BFS b = BFS(g, 2);
    std::vector<int> paths = d.pathTo(7);
    for (int i : paths){
        std::cout << i << " ";
    }
    std::cout << "\n--- \n";
    std::vector<int> shortestPaths = b.shortestPath(7);
    for (int i : shortestPaths){
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << d.hasPathTo(9) << "\n";
    std::cout << b.hasPathTo(9) << "\n";

}

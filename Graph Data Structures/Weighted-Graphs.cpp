//Edge.hpp
#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    public:
        int source;
        int connection;
        int weight;
        Edge(int s, int c, int w);
};

//Edge.cpp
#include "Edge.hpp"
#include <iostream>
#include <vector>
using namespace std;

Edge::Edge(int s, int c, int w){
    source = s;
    connection = c;
    weight = w;
}

//Compare.cpp
#include "Edge.cpp"
class Compare{
    public:
        bool operator()(const Edge* a, const Edge* b) const{
            return a->weight > b->weight;
        }
};

//WeightedGraph.hpp
#include <iostream>
#include <vector>
#include "Compare.cpp"
using namespace std;

class WeightedGraph{
    public:
        int V;
        std::vector<std::vector<Edge>> adj;
        WeightedGraph(int v);
        void addEdge(int v, int w, int weight);
        std::vector<Edge> returnAdjacent(int v);
        void print();
};

//WeightedGraph.cpp
#include <iostream>
#include <vector>
#include "WeightedGraph.hpp"
using namespace std;

WeightedGraph::WeightedGraph(int v){
    V = v;
    std::vector<vector<Edge>> temp(V);
    adj = temp;
    for (int i = 0; i < V; i++){
        std::vector<Edge> neighbors;
        adj[i] = neighbors;
    }
}

void WeightedGraph::addEdge(int v, int w, int weight){
    adj[v].push_back(Edge(v, w, weight));
    adj[w].push_back(Edge(w, v, weight));
}

std::vector<Edge> WeightedGraph::returnAdjacent(int v){
    return adj[v];
}

void WeightedGraph::print(){
    for (int i = 0; i < V; i++){
        std::cout << i << " | ";
        for (int j = 0; j < adj[i].size(); j++){
            std::cout << adj[i][j].connection << " = " << adj[i][j].weight << ", ";
        }
        std::cout << "\n";
    }
}

//Dijkstra.hpp
#include <iostream>
#include <vector>
#include "WeightedGraph.cpp"
#include <queue>
using namespace std;
class Dijkstra{
    public:
        std::priority_queue<Edge*, std::vector<Edge*>, Compare> pq;
        std::vector<int> edgeTo;
        std::vector<int> distTo;
        std::vector<int> marked;
        int S;
        int V;
        Dijkstra(WeightedGraph g, int s);
        void dijkstra(WeightedGraph g, int s);
        std::vector<int> pathTo(int t);
        bool hasPathTo(int t);
        std::vector<int> getDistTo(int t);
};

//Dijkstra.cpp
#include "Dijkstra.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

Dijkstra::Dijkstra(WeightedGraph g, int s){
    V = g.V;
    std::vector<int> tempEdgeTo(V);
    edgeTo = tempEdgeTo;
    std::vector<int> tempDistTo(V);
    distTo = tempDistTo;
    std::vector<int> tempMarked(V);
    marked = tempMarked;
    S = s;
    pq.push(new Edge(s, s, 0));
    distTo[s] = 0;
    for (int i = 0; i < V; i++){
        if (i != S){
            distTo[i] = INT_MAX;
        }
    }
    dijkstra(g, s);
}

void Dijkstra::dijkstra(WeightedGraph g, int s){
    while(!pq.empty()){
        Edge* n = pq.top();
        pq.pop();
        marked.push_back(n->connection);
        std::vector<Edge> neighbors = g.returnAdjacent(n->connection);
        for (Edge i : neighbors){
            if (std::find(marked.begin(), marked.end(), i.connection) == marked.end()){
                if (distTo[n->connection] + i.weight < distTo[i.connection]){
                    distTo[i.connection] = distTo[n->connection] + i.weight;
                    edgeTo[i.connection] = n->connection;
                    pq.push(new Edge(n->connection, i.connection, distTo[i.connection]));
                }
            }
        }
    }
}

std::vector<int> Dijkstra::pathTo(int t){
    std::vector<int> path;
    if (hasPathTo(t) == false){
        return path;
    }
    for (int i = t; i != S; i = edgeTo[i]){
        path.push_back(i);
    }
    path.push_back(S);
    std::reverse(path.begin(), path.end());
    return path;
}

bool Dijkstra::hasPathTo(int t){
    if (std::find(marked.begin(), marked.end(), t) != marked.end()){
        return true;
    }
    return false;
}

std::vector<int> Dijkstra::getDistTo(int t){
    return distTo;
}

//WeightedQuickUnion.cpp
#include <iostream>
#include <vector>
using namespace std;
class WeightedQuickUnion{
    public:
        std::vector<int> sets;
        WeightedQuickUnion(int size){
            std::vector<int> tempSet(size);
            sets = tempSet;
            for (int i = 0; i < size; i++){
                sets[i] = -1;
            } 
        }

        int root(int current){
            int i = current;
            while (sets[i] != -1){
                i = sets[i];
            }
            return i;
        }

        bool isConnected(int s, int t){
            return root(s) == root(t);
        }

        void connect(int s, int t){
            sets[root(s)] = root(t);
        }
};

//Kruskal.hpp
#include "Dijkstra.cpp"
#include "WeightedQuickUnion.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

class Kruskal{
    public:
        std::priority_queue<Edge*, std::vector<Edge*>, Compare> pq;
        std::vector<Edge> mst;
        Kruskal(WeightedGraph wg);
        void kruskal(WeightedGraph wg);
        std::vector<Edge> returnMST();
};

//Kruskal.cpp
#include "Kruskal.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

Kruskal::Kruskal(WeightedGraph wg){
    for (int i = 0; i < wg.V; i++){
        for (Edge j : wg.returnAdjacent(i)){
            pq.push(new Edge(j.source, j.connection, j.weight));
        }
    }
    kruskal(wg);
}

void Kruskal::kruskal(WeightedGraph wg){
    WeightedQuickUnion wqu = WeightedQuickUnion(wg.V);
    while (!pq.empty()){
        Edge* n = pq.top();
        pq.pop();
        if (wqu.isConnected(n->source, n->connection) == false){
            wqu.connect(n->source, n->connection);
            mst.push_back(Edge(n->source, n->connection, n->weight));
        }
    }
}

std::vector<Edge> Kruskal::returnMST(){
    return mst;
}

//main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include "Kruskal.cpp"
using namespace std;

int main(){
    WeightedGraph wg = WeightedGraph(11);
    wg.addEdge(0, 1, 1);
    wg.addEdge(1, 2, 2);
    wg.addEdge(1, 4, 3);
    wg.addEdge(2, 5, 4);
    wg.addEdge(3, 4, 5);
    wg.addEdge(4, 5, 6);
    wg.addEdge(5, 6, 7);
    wg.addEdge(5, 8, 8);
    wg.addEdge(6, 7, 9);
    wg.print();
    std::cout << " --- \n";
    int start = 0;
    int end = 7;

    Dijkstra d = Dijkstra(wg, start);
    std::cout << "Shortest Path From " << start << " to " << end << ": \n";
    for (int i : d.pathTo(end)){
        std::cout << i << " => ";
    }
    std::cout << "\n";
    std::vector<int> distTo = d.getDistTo(end);
    std::cout << "Total Weight: " << distTo[end];
    std::cout << "\n --- \n";

    Kruskal k = Kruskal(wg);
    std::cout << "MST: \n";
    for (Edge i : k.returnMST()){
        std::cout << i.source << " <=> " << i.connection << ": " << i.weight << "\n";
    }
}

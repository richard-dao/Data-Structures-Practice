// Java
import java.util.*;
public class Edge implements Comparator<Edge>{
    int source;
    int connection;
    int weight;
    public Edge(){}
    public Edge(int source, int connection, int weight){
        this.source = source;
        this.connection = connection;
        this.weight = weight;
    }
    @Override
    public int compare(Edge n1, Edge n2){
        if (n1.weight < n2.weight){
            return -1;
        }
        if (n1.weight > n2.weight){
            return 1;
        }
        return 0;
    }
    
}

// Weighted Graph

import java.util.*;
public class WeightedGraphs {
    int V;
    ArrayList<Edge>[] adj;
    public WeightedGraphs(int V){
        this.V = V;
        adj = (ArrayList<Edge>[]) new ArrayList[V];
        for (int i = 0; i < V; i++){
            adj[i] = new ArrayList<Edge>();
        }
    }

    public void addEdge(int v, int w, int weight){
        adj[v].add(new Edge(v, w, weight));
        adj[w].add(new Edge(w, v, weight)); // Comment out line for directed graph
    }

    public Iterable<Edge> returnAdjacent(int v){
        return adj[v];
    }

    public void print(){
        for (int i = 0; i < V; i++){
            System.out.print(i + " | ");
            for (int j = 0; j < adj[i].size(); j++){
                System.out.print(adj[i].get(j).connection + " = " + adj[i].get(j).weight + ", ");
            }
            System.out.println();
        }
    }
}

// Dijkstra

import java.util.*;
public class Dijkstra{
    PriorityQueue<Edge> pq;
    int[] edgeTo;
    int[] distTo;
    Set<Integer> marked;
    int s;
    int V;
    public Dijkstra(WeightedGraphs g, int s){
        this.V = g.V;
        pq = new PriorityQueue<Edge>(V, new Edge());
        edgeTo = new int[V];
        distTo = new int[V];
        marked = new HashSet<Integer>();
        this.s = s;
        pq.add(new Edge(s, s, 0));
        distTo[s] = 0;
        for (int i = 0; i < V; i++){
            if (i != s){
                distTo[i] = Integer.MAX_VALUE;
            }
        }
        
        dijkstra(g, s);
    }

    public void dijkstra(WeightedGraphs g, int s){
        while (!pq.isEmpty()){
            Edge n = pq.poll();
            marked.add(n.connection);
            for (Edge i : g.returnAdjacent(n.connection)){
                if (!marked.contains(i.connection)){
                    if (distTo[n.connection] + i.weight < distTo[i.connection]){
                        distTo[i.connection] = distTo[n.connection] + i.weight;
                        edgeTo[i.connection] = n.connection;
                        pq.add(new Edge(n.connection, i.connection, distTo[i.connection]));
                    }
                }
            }
        }
    }

    public Iterable<Integer> pathTo(int t){
        if ((hasPathTo(t)) == false){
            return null;
        }
        ArrayList<Integer> path = new ArrayList<Integer>();
        for (int i = t; i != s; i = edgeTo[i]){
            path.add(i);
        }
        path.add(s);
        Collections.reverse(path);
        return path;

    }

    public boolean hasPathTo(int t){
        if (marked.contains(t)){
            return true;
        }
        return false;
    }

    public int[] getDistTo(int t){
        return distTo;
    }

}

// Kruskal

public class WeightedQuickUnion {
    int[] sets;
    public WeightedQuickUnion(int size){
        sets = new int[size];
        for (int i = 0; i < size; i++){
            sets[i] = -1;
        }
    }

    public int root(int current){
        int i = current;
        while (sets[i] != -1){
            i = sets[i];
        }
        return i;
    }

    public boolean isConnected(int s, int t){
        return root(s) == root(t);
    }

    public void connect(int s, int t){
        sets[root(s)] = root(t);
    }
    
}

import java.util.*;
public class Kruskal {
    PriorityQueue<Edge> pq; // Edges
    ArrayList<Edge> mst; 
    public Kruskal(WeightedGraphs wg){
        mst = new ArrayList<Edge>();
        pq = new PriorityQueue<Edge>(wg.V, new Edge());
        for (int i = 0; i < wg.V; i++){
            for (Edge j : wg.returnAdjacent(i)){
                pq.add(j);
            }
        }
        kruskal(wg);
    }

    public void kruskal(WeightedGraphs wg){
        WeightedQuickUnion wqu = new WeightedQuickUnion(wg.V);
        while (!pq.isEmpty()){
            Edge n = pq.poll();
            if (wqu.isConnected(n.source, n.connection) == false){
                wqu.connect(n.source, n.connection);
                mst.add(n);
            }

        }
    }

    public Iterable<Edge> returnMST(){
        return mst;
    }
}

import java.util.Map;

public class main {
    public static void main(String[] args){
        WeightedGraphs wg = new WeightedGraphs(11);
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
        System.out.println("---");
        int start = 0;
        int end = 7;
        // O(V + E log V)
        Dijkstra d = new Dijkstra(wg, start);
        System.out.println("Shortest Path From " + start + " to " + end + ": ");
        for (int i : d.pathTo(end)){
            System.out.print(i + " => ");
        }
        System.out.println();
        int[] distTo = d.getDistTo(end);
        System.out.println("Total Weight: " + distTo[end]);
        System.out.println("---");

        Kruskal k = new Kruskal(wg);
        System.out.println("MST: ");

        for (Edge i : k.returnMST()){
            System.out.println(i.source + " <=> " + i.connection + ": " + i.weight);
        }
    }
}




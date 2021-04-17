//Java
import java.util.*;
public class Edge implements Comparator<Edge>{
    int connection;
    int weight;
    public Edge(){}
    public Edge(int connection, int weight){
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
        adj[v].add(new Edge(w, weight));
        adj[w].add(new Edge(v, weight));
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


// Implement Dijkstra's Algorithm
import java.util.*;
public class Dijkstra {
    int[] distTo;
    int[] edgeTo;
    Set<Integer> marked;
    PriorityQueue<Edge> pq;
    int s;
    int V;
    public Dijkstra(WeightedGraphs g, int s){
        this.s = s;
        V = g.V;
        distTo = new int[V];
        edgeTo = new int[V];
        marked = new HashSet<Integer>();
        pq = new PriorityQueue<Edge>(V, new Edge());
        dijkstra(g, s);
    }

    public void dijkstra(WeightedGraphs g, int v){
        for (int i = 0; i < V; i++){
            distTo[i] = Integer.MAX_VALUE;
        }
        pq.add(new Edge(s, 0));
        distTo[s] = 0;
        while (pq.isEmpty() == false){
            int n = pq.remove().connection;
            marked.add(n);
            relaxEdges(g, n);
        }        
    }

    public void relaxEdges(WeightedGraphs g, int v){
        int weight;
        int totalWeight;
        for (Edge i : g.returnAdjacent(v)){
            Edge n = i;
            if (!marked.contains(n.connection)){
                weight = n.weight;
                totalWeight = distTo[v] + weight;
                if (totalWeight < distTo[n.connection]){
                    distTo[n.connection] = totalWeight;
                    edgeTo[n.connection] = v;
                }
                pq.add(new Edge(n.connection, distTo[n.connection]));
            }
        }
    }

    public Iterable<Integer> shortestPathTo(int v){
        if (hasPathTo(v) == false){
            return null;
        }
        ArrayList<Integer> path = new ArrayList<Integer>();
        for (int i = v; i != s; i = edgeTo[i]){
            path.add(i);
        }
        path.add(s);
        Collections.reverse(path);
        return path;
    }

    public boolean hasPathTo(int v){
        if (marked.contains(v)){
            return true;
        }
        return false;
    }
    
    public int[] returnDistTo(){
        return distTo;
    }

}

// Implement Kruskal's Algorithm


import java.util.*;

public class main {
    public static void main(String[] args){
        WeightedGraphs wg = new WeightedGraphs(10);
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
        Dijkstra d = new Dijkstra(wg, 0);
        int[] distTo = d.returnDistTo();
        for (int i = 0; i < distTo.length; i++){
            System.out.println(i + " | " + distTo[i] + " ");
        }
        System.out.println("---");
        for (int i : d.shortestPathTo(8)){
            System.out.print(i + " => ");
        }


    }
}


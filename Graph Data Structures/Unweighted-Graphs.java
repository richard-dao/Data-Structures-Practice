import java.util.*;
public class Graphs {
    int V;
    List<Integer>[] adj;

    public Graphs(int V){
        this.V = V;
        adj = (List<Integer>[]) new ArrayList[V];
        for (int i  = 0 ; i < V; i++){
            adj[i] = new ArrayList<Integer>();
        }
    }

    public void addEdge(int v, int w){
        adj[w].add(v);
        adj[v].add(w); // Remove this for Directed Graphs
    }

    public Iterable<Integer> returnAdjacent(int v){
        return adj[v];
    }

    public void print(){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < adj[i].size(); j++){
                System.out.print(i + "-" + adj[i].get(j) + " ");
            }
            System.out.println();
        }
    }
}
import java.util.*;
public class DFS {
    boolean[] marked;
    int[] edgeTo;
    int s;
    
    public DFS(Graphs graphs, int s){
        this.s = s;
        this.marked = new boolean[graphs.V];
        this.edgeTo = new int[graphs.V];
        dfs(graphs, s);
    }

    public void dfs(Graphs graphs, int v){
        marked[v] = true;
        for (int i : graphs.returnAdjacent(v)){
            if (marked[i] != true){
                edgeTo[i] = v;
                dfs(graphs, i);
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
        return marked[t];
    }

    public boolean[] getMarked(){
        return marked;
    }

    public int[] getEdgeTo(){
        return edgeTo;
    }
}

import java.util.*;

public class BFS{
    boolean[] marked;
    int[] edgeTo;
    int s;
    public BFS(Graphs graph, int s){
        this.s = s;
        marked = new boolean[graph.V];
        edgeTo = new int[graph.V];
        bfs(graph, s); 
    }

    public void bfs(Graphs graph, int v){
        Queue<Integer> q = new LinkedList<Integer>();
        marked[s] = true;
        q.add(s);

        while (q.peek() != null){
            int n = q.remove();
            Iterable<Integer> adj = graph.returnAdjacent(n);
            for (int i : adj){
                if (!marked[i]){
                    q.add(i);
                    marked[i] = true;
                    edgeTo[i] = n;
                }
            }
        }
        
    }

    public Iterable<Integer> shortestPath(int t){
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
        return marked[t];
    }

    public boolean[] getMarked(){
        return marked;
    }

    public int[] getEdgeTo(){
        return edgeTo;
    }
}

public class main {
    public static void main(String[] args){
        Graphs g = new Graphs(10);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.addEdge(3, 4);
        g.addEdge(4, 5);
        g.addEdge(5, 6);
        g.addEdge(5, 8);
        g.addEdge(6, 7);
        g.print();
        System.out.println("---");
        DFS d = new DFS(g, 2);
        BFS b = new BFS(g, 2);
        for (int i : d.pathTo(7)){
            System.out.print(i + " ");
        }
        System.out.println();
        for(int i : b.shortestPath(7)){
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.println(d.hasPathTo(9));
        System.out.printn(b.hasPathTo(9));

    }
}

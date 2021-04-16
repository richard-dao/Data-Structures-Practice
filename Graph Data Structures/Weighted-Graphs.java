//Java
import java.util.*;
public class WeightedGraphs {
    int V;
    List<Map<Integer, Integer>>[] adj;
    public WeightedGraphs(int V){
        this.V = V;
        adj = (List<Map<Integer, Integer>>[]) new ArrayList[V];
        for (int i = 0; i < V; i++){
            adj[i] = new ArrayList<Map<Integer, Integer>>();
        }
    }

    public void addEdge(int v, int w, int weight){
        Map<Integer, Integer> one = new HashMap<Integer, Integer>();
        one.put(w, weight);
        adj[v].add(one);
        Map<Integer, Integer> two = new HashMap<Integer, Integer>();
        two.put(v, weight);
        adj[w].add(two);
    }

    public Iterable<Map<Integer, Integer>> returnAdjacent(int v){
        return adj[v];
    }

    public void print(){
        for (int i = 0; i < V; i++){
            System.out.print(i + " | ");
            for (int j = 0; j < adj[i].size(); j++){
                Map<Integer, Integer> mp = adj[i].get(j);
                for (Map.Entry<Integer, Integer> k : mp.entrySet()){
                    int key = k.getKey();
                    int value = k.getValue();
                    System.out.print(key + " = " + value + ", ");
                }
            }
            System.out.println();
        }
    }
}
// Implement Dijkstra's Algorithm

// Implement Kruskal's Algorithm


import java.util.Map;

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
        for (Map<Integer, Integer> i : wg.returnAdjacent(5)){
            Map.Entry<Integer, Integer> j = i.entrySet().iterator().next();
            int key = j.getKey();
            int value = j.getValue();
            System.out.println(key + " = " + value);
        }

    }
}

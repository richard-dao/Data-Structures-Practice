//Java
public class PriorityNode {
    int value;
    int level;
    PriorityNode next;
    public PriorityNode(int value, int level){
        this.value = value;
        this.level = level;
    }
}
public class PriorityQueue {
    PriorityNode head;
    public PriorityQueue(){
        head = null;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public int peek(){
        if (isEmpty()){
            return -999;
        }
        PriorityNode current = head;
        PriorityNode minNode = head;
        while (current != null){
            if (current.level < minNode.level){
                minNode = current;
            }
            current = current.next;
        }
        return minNode.value;
    }
    
    public void enqueue(int value, int level){
        if (isEmpty()){
            head = new PriorityNode(value, level);
            return;
        }
        PriorityNode current = head;
        while (current.next != null){
            current = current.next;
        }
        current.next = new PriorityNode(value, level);
    }

    public int dequeue(){
        PriorityNode current = head;
        PriorityNode minNode = head;
        PriorityNode prev = null;
        PriorityNode prevMin = null;
        if (isEmpty()){
            return -999;
        }
        while (current != null){
            if (current.level < minNode.level){
                minNode = current;
                prevMin = prev;
            }
            prev = current;
            current = current.next;
        }
        if (minNode == head){
            head = head.next;
            if (head == null){
                return -999;
            }
            return head.value;
        }
        int value = minNode.value;
        prevMin.next = prevMin.next.next;
        return value;
    }

    public void display(){
        PriorityNode current = head;
        while (current != null){
            System.out.println("[" + Integer.toString(current.value) + " : " + Integer.toString(current.level) + "]");
            current = current.next;
        }
    }
}
import java.util.ArrayList;

public class main{
    public static void main(String[] args){
        PriorityQueue p = new PriorityQueue();
        p.enqueue(9, 4);
        p.enqueue(10, 3);
        p.enqueue(13, 5);
        p.enqueue(10, 2);
        p.enqueue(8, 2);
        System.out.println(p.peek());
        p.dequeue();
        System.out.println(p.peek());
        p.display();
    }
}

//Java
//Linked List Queue
public class QueueNode {
	int value;
	QueueNode next;
	public QueueNode(int value) {
		this.value = value;
	}
}

import java.util.ArrayList;
public class Queue {
	QueueNode head;
	QueueNode tail;
	public boolean isEmpty() {
		return head == null;
	}
	
	public int peek() {
		return head.value;
	}
	
	public void push(int value) {
		QueueNode newNode = new QueueNode(value);
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
			return;
		}
		tail.next = newNode;
		tail = newNode;
	}
	
	public void pop() {
		if (isEmpty()) {
			return;
		}
		if(head.next == null) {
			head = null;
			tail = null;
			return;
		}
		head = head.next;
	}
	
	public ArrayList<Integer> display() {
		ArrayList<Integer> rArr = new ArrayList<Integer>();
		QueueNode current = head;
		while (current != null) {
			rArr.add(current.value);
			current = current.next;
		}
		return rArr;
		
	}
}

public class main {
	public static void main(String[] args) {
		Queue s = new Queue();
		System.out.println(s.isEmpty());
		s.push(0);
		s.push(1);
		s.push(2);
		s.push(3);
		s.pop();
		printL(s.display());
		System.out.println("Top: " + s.peek());
  }
}

//Array Queues
import java.util.ArrayList;
public class Queue {
	int[] queue; 
	int headIndex;
	int tailIndex;
	public Queue(int length) {
		queue = new int[length];
		headIndex = 0;
		tailIndex = 0;
	}
	
	public boolean isEmpty() {
		return headIndex == tailIndex;
	}
	
	public int peek() {
		if (isEmpty()) {
			return -1;
		}
		return queue[headIndex];
	}
	
	public void push(int value) {
		queue[tailIndex] = value;
		tailIndex++;
		if (tailIndex > queue.length) {
			tailIndex = 0;
		}
		return;
		
	}
	
	public void pop() {
		if (isEmpty()) {
			return;
		}
		headIndex++;
		if (headIndex > queue.length) {
			headIndex = 0;
		}
	}
	
	public ArrayList<Integer> display() {
		ArrayList<Integer> rArr = new ArrayList<Integer>();
		if (isEmpty()) {
			return rArr;
		}
		if (tailIndex < headIndex) {
			for (int i = headIndex; i < queue.length; i++) {
				rArr.add(queue[i]);
			}
			for (int i = 0; i < tailIndex; i++) {
				rArr.add(queue[i]);
			}
			
		}
		else {
			for (int i = headIndex; i < tailIndex; i++) {
				rArr.add(queue[i]);
			}
		}
		return rArr;
	}

}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		Queue s = new Queue(5);
		s.push(1);
		s.pop();
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		System.out.println(s.isEmpty());
		printL(s.display());
		System.out.println("Top: " + s.peek());
  }
}

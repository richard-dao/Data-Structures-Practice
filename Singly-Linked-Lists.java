//Java

//Node Class
public class Node {
	Node next;
	int value;
	public Node(int value) {
		this.value = value;
	}
}

//LinkedList Class
public class LinkedList {
	Node head;
	
	public void append(int value) {
		if (head == null) {
			head = new Node(value);
			return;
		}
		Node current = head;
		while (current.next != null) {
			current = current.next;
		}
		current.next = new Node(value);
	}
	
	public void prepend(int value) {
		Node newHead = new Node(value);
		newHead.next = head;
		head = newHead;
	}
	
	public void deleteFirst(int value) {
		if (head == null) {
			return;
		}
		if (head.value == value) {
			head = head.next;
			return;
		}
		Node current = head;
		while (current.next != null) {
			if (current.next.value == value) {
				current.next = current.next.next;
				return;
			}
			current = current.next;
		}
	}
	
	public void deleteAll(int value) {
		if (head == null) {
			return;
		}
		Node current = head;
		while (current.next != null) {
			if (current.next.value == value) {
				current.next = current.next.next;
			}
			else{
				current = current.next;
			}
		}
		if (head.value == value) {
			head = head.next;
		}	
	}
	
	public int getLength() {
		if (head == null) {
			return 0;
		}
		int count = 0;
		Node current = head;
		while(current != null) {
			count++;
			current = current.next;
		}
		return count;
	}
	
	public int[] getValues() {
		Node current = head;
		int[] rValues = new int[getLength()];
		
		if (head == null) {
			return rValues;
		}
		int i = 0;
		while (current != null) {
			rValues[i] = current.value;
			i++;
			current = current.next;
		}
		return rValues;
	}
	
	public void reverse() {
		Node prev = null;
		Node current = head;
		Node next;
		
		while(current != null) {
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	
	public void insert(int value, int position) {
		int counter = 0;
		Node current = head;
		if (counter == position) {
			prepend(value);
			return;
		}
		else {
			while(counter + 1 < position && current.next != null) {
				current = current.next;
				counter++;
			}
		}
		if (current.next == null) {
			return;
		}
		Node next = current.next;
		Node inserted = new Node(value);
		current.next = inserted;
		inserted.next = next;
	}
}

//Main File
import java.util.ArrayList;
public class main {
	public static void main(String[] args) {
		LinkedList l = new LinkedList();
		l.append(0);
		l.append(1);
		l.append(2);
		l.append(3);
		l.append(4);
		l.append(0);
		int[] lList;
		// 0 -> 1 -> 2 -> 3 -> 4 -> 0 -> NULL
		System.out.println(l.getLength());
		printLinkedList(l);
		l.deleteAll(0);
		//1 -> 2 -> 3 -> 4 -> NULL
		System.out.println();
		System.out.println(l.getLength());
		printLinkedList(l);
		System.out.println();
		l.prepend(1);
		//1 -> 1 -> 2 -> 3 -> 4 -> NULL
		printLinkedList(l);
		l.deleteAll(1);
		//2 -> 3 -> 4 -> NULL
		System.out.println();
		printLinkedList(l);
		l.prepend(0);
		System.out.println();
		printLinkedList(l);
		//0 -> 2 -> 3 -> 4 -> NULL
		l.reverse();
		System.out.println();
		printLinkedList(l);
		//4 -> 3 -> 2 -> 0 -> NULL
		l.reverse();
		System.out.println();
		printLinkedList(l);
		//0 -> 2 -> 3 -> 4 -> NULL
		l.append(0);
		//0 -> 2 -> 3 -> 4 -> 0 -> NULL
		System.out.println();
		printLinkedList(l);
		l.deleteFirst(0);
		// 2 -> 3 -> 4 -> 0 -> NULL
		System.out.println();
		printLinkedList(l);
		l.insert(1, 1);
		//2 -> 1 -> 3 -> 4 -> 0 -> NULL
		System.out.println();
		printLinkedList(l);
		l.insert(9, 0);
		//9 -> 2 -> 1 -> 3 -> 4 -> 0 -> NULL
		System.out.println();
		printLinkedList(l);
	}
	public static void printLinkedList(LinkedList k) {
		int[] lList = k.getValues();
		for (int i = 0; i < lList.length; i++) {
			System.out.print(lList[i] + ", ");
		}
	}
}



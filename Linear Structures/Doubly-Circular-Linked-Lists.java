//Java

public class DoublyCircularlyNode {
	int value;
	DoublyCircularlyNode next;
	DoublyCircularlyNode prev;
	public DoublyCircularlyNode(int value) {
		this.value = value;
		this.next = null;
		this.prev = null;
	}
}

public class DoublyCircularlyLinkedList {
	DoublyCircularlyNode last;
	
	public int[] getValues() {
		int[] rArr = new int[getLength()];
		if (last == null) {
			return rArr;
		}
		DoublyCircularlyNode current = last;
		for (int i = 0; i < rArr.length; i++) {
			rArr[i] = current.next.value;
			current = current.next;
		}
		rArr[getLength()-1] = last.value;
		return rArr;
	}
	
	public int getLength() {
		int counter = 0;
		DoublyCircularlyNode current = last;
		if (last == null) {
			return 0;
		}
		while (current.next != last) {
			counter++;
			current = current.next;
		}
		return counter + 1;
	}
	
	public void append(int value) {
		DoublyCircularlyNode newNode = new DoublyCircularlyNode(value);
		if (last == null) {
			last = newNode;
			last.prev = last;
			last.next = last;
			return;
		}
		newNode.prev = last;
		newNode.next = last.next;
		last.next.prev = newNode;
		last.next = newNode;
		last = newNode;
	}
	
	public void prepend(int value) {
		DoublyCircularlyNode newNode = new DoublyCircularlyNode(value);
		if (last == null) {
			append(value);
			return;
		}
		newNode.prev = last;
		newNode.next = last.next;
		last.next.prev = newNode;
		last.next = newNode;
	}
	
	public void insert(int value, int position) {
		if (last == null || position == 0) {
			prepend(value);
			return;
		}
		
		if (position > getLength()-1) {
			append(value);
			return;
		}
		DoublyCircularlyNode current = last.next;
		DoublyCircularlyNode newNode = new DoublyCircularlyNode(value);
		int counter = 0;
		while (counter + 1 < position && current.next != last) {
			current = current.next;
			counter++;
		}
		newNode.prev = current;
		newNode.next = current.next;
		current.next.prev = newNode;
		current.next = newNode;
	}
	
	public void deleteFirst(int value) {
		if (last == null) {
			return;
		}
		if (last.next == last && last.value == value) {
			last = null;
			return;
		}
		DoublyCircularlyNode current = last;
		while (current.next.value != value && current.next != last) {
			current = current.next;
		}
		if (current.next == last && last.value == value) {
			last.prev.next = last.next;
			last.next.prev = last.prev;
			last = last.prev;
			return;
		}
		else if (current.next == last) {
			return;
		}
		else{
			current.next = current.next.next;
			current.next.prev = current;
		}
		
	}
	
	public void deleteAll(int value) {
		if (last == null) {
			return;
		}
		DoublyCircularlyNode current = last.next;
		while (current != last) {
			if (current.value == value) {
				deleteFirst(value);
			}
			current = current.next;
		}
		deleteFirst(value);
	}
	
	public void deleteAt(int position) {
		if (last == null || position > getLength()-1) {
			return;
		}
		if (last.next == last) {
			if (position == 0) {
				last = null;
				return;
			}
		}
		
		DoublyCircularlyNode current = last;
		// 0 -> 1 -> 2 
		int counter = 0;
		while (current.next != last && counter < position) {
			current = current.next;
			counter++;
		}
		if (current.next == last) {
			last.prev.next = last.next;
			last.next.prev = last.prev;
			last = last.prev;
			return;
		}
		current.next = current.next.next;
		current.next.prev = current;
	}
	
	public void reverse() {
		if (last == null) {
			return;
		}
		DoublyCircularlyNode previous = last;
		DoublyCircularlyNode current = last.next;
		DoublyCircularlyNode next;
		
		while (current != last) {
			next = current.next;
			current.next = previous;
			current.prev = next;
			previous = current;
			current = next;
		}
		next = current.next;
		current.next = previous;
		current.prev = next;
		last = next;
	}
	
	public void setLast(DoublyCircularlyNode newLast) {
		last = newLast;
	}
	
	public DoublyCircularlyNode getLast() {
		return last;
	}
	public DoublyCircularlyNode reverseRecursive(DoublyCircularlyNode previous, DoublyCircularlyNode current, DoublyCircularlyNode stop) {
		DoublyCircularlyNode next;
		if (current == stop) {
			next = current.next;
			current.next = previous;
			current.prev = next;
			return next;
		}
		next = current.next;
		current.next = previous;
		current.prev = next;
		return reverseRecursive(current, next, stop);
	}
	
}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		DoublyCircularlyLinkedList l = new DoublyCircularlyLinkedList();
		
		l.append(0);
		l.insert(2, 2);
		l.insert(3, 4);
		l.append(1);
		l.append(1);
		l.append(1);
		l.prepend(-1);
		l.deleteAll(1);
		l.deleteAt(1);
		l.reverse();
		l.setLast(l.reverseRecursive(l.getLast(), l.getLast().next, l.getLast()));
		System.out.println(l.getLength());
		
		printL(l.getValues());
		
	}
	public static void printL(int[] ll) {
		System.out.println();
		for (int i = 0; i < ll.length; i++) {
			System.out.print(ll[i] + ", ");
		}
		System.out.println();
	}
}

//Java
public class CircularlyNode {
	int value;
	String ifNull;
	CircularlyNode next;
	public CircularlyNode(int value) {
		this.value = value;
		this.next = null;
	}
}

public class CircularlyLinkedList {
	CircularlyNode last;
	
	public void append(int value) {
		CircularlyNode newNode = new CircularlyNode(value);
		if (last == null) {
			last = newNode;
			last.next = last;
			return;
		}
		newNode.next = last.next;
		last.next = newNode;
		last = newNode;
	}
	
	public void prepend(int value) {
		CircularlyNode newNode = new CircularlyNode(value);
		if (last == null) {
			last = newNode;
			last.next = last;
			return;
		}
		newNode.next = last.next;
		last.next = newNode;
	}
	
	public void insert(int value, int position) {
		CircularlyNode current = last.next;
		CircularlyNode newNode = new CircularlyNode(value);
		int counter = 0;
		
		if (last == null || position == 0) {
			append(value);
			return;
		}
		
		if (position > getLength()-1) {
			append(value);
			return;
		}
		
		while (current.next != last && counter + 1 < position) {
			current = current.next;
			counter++;
		}
		newNode.next = current.next;
		current.next = newNode;
	}
	
	public void deleteFirst(int value) {
		CircularlyNode current = last;
		if (last == null) {
			return;
		}
		while (current.next != last && current.next.value != value) {
			current = current.next;
		}
		
		if (current.next.value != value) {
			return;
		}
		else if (current.next != last){
			current.next = current.next.next;
		}
		else {
			CircularlyNode tempCurrent = last;
			if (last.value == value) {
				if (last.next == last) {
					last = null;
					return;
				}
				while(tempCurrent.next != last) {
					tempCurrent = tempCurrent.next;
				}
				tempCurrent.next = tempCurrent.next.next;
				last = tempCurrent;
				return;
				
			}
		}
	}
	
	public void deleteAll(int value) {
		CircularlyNode current = last.next;
		if (last == null) {
			return;
		}
		int counter = 0;
		while (current.next != last) {
			if (current.value == value) {
				counter++;
			}
			current = current.next;
		}
		if (last.value == value) {
			counter = counter +1;
		}
		for (int i = 0; i <= counter; i++) {
			deleteFirst(value);
		}
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
		
		CircularlyNode current = last;
		int counter = 0;
		while (current.next != last && counter < position) {
			current = current.next;
			counter++;
		}
		
		if (position == getLength()-1) {
			current.next = last.next;
			last = current;
			return;
		}
		current.next = current.next.next;
		
	}
	
	public int getLength() {
		CircularlyNode current = last;
		if (last == null) {
			return 0;
		}
		int counter = 0;
		while (current.next != last) {
			counter++;
			current = current.next;
		}
		return counter+1;
		
	}
	
	public int[] getValues() {
		CircularlyNode current = last;
		
		int[] rArr = new int[getLength()];
		if (last == null) {
			return rArr;
		}
		for (int i = 0; i < rArr.length; i++) {
			current = current.next;
			rArr[i] = current.value;
		}
		rArr[rArr.length-1] = last.value;
		return rArr;
	}
	
	public void reverse() {
		
		CircularlyNode prev = last;
		CircularlyNode current = last.next;
		CircularlyNode next;
		
		while (current != last) {
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		next = current.next;
		current.next = prev;
		prev = current;
		last = next;
	}
	
	public CircularlyNode getPrev() {
		CircularlyNode current = last;
		while(current.next != last) {
			current = current.next;
		}
		return current;
	}
	
	public CircularlyNode reverseRecursive(CircularlyNode current, CircularlyNode previous, CircularlyNode stop) {
		CircularlyNode next;
		
		if (current.next == stop) {
			next = current.next;
			current.next = previous; 
			return next;
		}
		next = current.next;
		current.next = previous;
		return reverseRecursive(next, current, stop);
	}
	
	public CircularlyNode getLast() {
		return last;
	}
	
	public void setLast(CircularlyNode newLast) {
		last = newLast;
	}
}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		CircularlyLinkedList l = new CircularlyLinkedList();
		l.append(0);
		l.append(1);
		l.append(2);
		l.append(3);
		l.append(3);
		l.prepend(-1);
		l.insert(9, 5);
		l.append(3);
		l.deleteFirst(3);
		l.append(3);
		l.append(3);
		l.deleteAll(3);
		
		printL(l.getValues());
		l.deleteAt(4);
		printL(l.getValues());
		l.reverse();
		printL(l.getValues());
		l.setLast(l.reverseRecursive(l.getLast().next, l.getLast(), l.getLast().next));
		printL(l.getValues());
		System.out.println();
		
		
	}
	public static void printL(int[] ll) {
		System.out.println();
		for (int i = 0; i < ll.length; i++) {
			System.out.print(ll[i] + ", ");
		}
	}
}




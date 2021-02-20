//Java

public class DoublyNode {
	DoublyNode prev;
	int value;
	DoublyNode next;
	public DoublyNode(int value) {
		this.value = value;
	}
}


public class DoublyLinkedList {
	DoublyNode head;
	public DoublyNode getHead() {
		return head;
	}
	
	public void setHead(DoublyNode head) {
		this.head = head;
	}
	
	public DoublyNode getTail() {
		DoublyNode current = head;
		if (head == null) {
			return head;
		}
		while (current.next != null) {
			current = current.next;
		}
		return current;
	}
	
	public void append(int value) {
		DoublyNode current = head;
		if (current == null) {
			head = new DoublyNode(value);
			return;
		}
		while (current.next != null) {
			current = current.next;
		}
		
		current.next = new DoublyNode(value);
		current.next.prev = current;
		
	}
	
	public void prepend(int value) {
		DoublyNode current = head;
		if (current == null) {
			head = new DoublyNode(value);
			return;
		}
		DoublyNode newHead = new DoublyNode(value);
		newHead.next = head;
		head.prev = newHead;
		head = newHead;
		
	}
	
	public void insert(int value, int position) {
		DoublyNode current = head;
		if (head == null) {
			prepend(value);
			return;
		}
		if (position == 0) {
			prepend(value);
			return;
		}
		int count = 0;
		while (count + 1 < position) {
			current = current.next;
			count++;
		}
		
		if (current.next == null) {
			append(value);
			return;
		}
		
		DoublyNode inserted = new DoublyNode(value);
		DoublyNode nextTemp = current.next;
		current.next = inserted;
		inserted.prev = current;
		inserted.next = nextTemp;
		nextTemp.prev = inserted;
	}
	
	public void deleteFirst(int value) {
		DoublyNode current = head;
		if (head == null) {
			return;
		}
		
		if (head.value == value) {
			head = current.next;
			head.prev = null;
			return;
		}
		
		while (current.value != value && current != null) {
			current = current.next;
		}
		if (current != null && current.next != null) {
			current.prev.next = current.next;
			current.next.prev = current.prev;
		}
		else if (current != null) {
			current.prev.next = current.next;
			
		}
		else {
			return;
		}
		return;
	}
	
	public void deleteAt(int position) {
		DoublyNode current = head;
		if (head == null) {
			return;
		}
		if (position == 0 && head.next != null) {
			DoublyNode newHead = head.next;
			head = newHead;
			head.prev = null;
			return;
		}
		else if (position == 0) {
			head = null;
			return;
		}
		
		int counter = 0; 
		while (counter + 1 < position && current != null) {
			current = current.next;
			counter++;
		}
		
		if (current == null) {
			return;
		}
		else if (current.next == null) {
			current.next = null;
		}
		else if (current.next.next == null) {
			current.next = null;
		}
		else {
			current.next = current.next.next;
			current.next.prev = current;
		}
		return;
	}
	
	public void deleteAll(int value) {
		DoublyNode current = head;
		if (head == null) {
			return;
		}
		while (current != null) {
			if (head.value == value && head.next != null) {
				head = head.next;
				head.prev = null;
			}
			else if (head.value == value) {
				head = null;
				return;
			}
			else if (current.value == value && current.next != null) {
				current.prev.next = current.next;
				current.next.prev = current.prev;
			}
			else if (current.value == value) {
				current.prev.next = null;
			}
			current = current.next;
		}
	
	}
	
	public int getLength() {
		int counter = 0;
		DoublyNode current = head;
		while (current != null) {
			current = current.next;
			counter++;
		}
		return counter;
	}
	
	public int[] getValues() {
		int[] rArr = new int[getLength()];
		DoublyNode current = head;
		for (int i = 0; i < rArr.length; i++) {
			rArr[i] = current.value;
			current = current.next;
		}
		return rArr;
	}
	
	public void reverse() {
		DoublyNode current = head;
		DoublyNode tempNext;
		
		if (head == null) {
			return;
		}
		
		while (current != null) {
			if (current.next == null) {
				current.next = current.prev;
				current.prev = null;
				head = current;
				return;
			}
			tempNext = current.next;
			current.next = current.prev;
			current.prev = tempNext;
			current = tempNext;
			
		}
		head = current;
		
	}
	
	public DoublyNode reverseRecursive(DoublyNode current) {
		if (current.next == null) {
			current.next = current.prev;
			current.prev = null;
			return current;
		}
		DoublyNode tempNext = current.next;
		current.next = current.prev;
		current.prev = tempNext;
		return reverseRecursive(tempNext);
		
	}
}

public class main {
	public static void main(String[] args) {
		DoublyLinkedList l = new DoublyLinkedList();
		DoublyLinkedList l = new DoublyLinkedList();
    l.prepend(1);
    l.prepend(0);
    l.append(2);
    l.append(1);
    l.append(2);
    l.insert(4,3);
    l.deleteFirst(2);
    l.append(3);
    l.deleteAt(4);
    l.append(1);
    l.append(1);
    l.deleteAll(1);
    l.reverse();
		l.setHead(l.reverseRecursive(l.getHead()));
		printLinkedList(l.getValues());
		
	}
	public static void printLinkedList(int[] ll) {
		System.out.println();
		for (int i = 0; i < ll.length; i++) {
			System.out.print(ll[i] + ", ");
		}
	}
}


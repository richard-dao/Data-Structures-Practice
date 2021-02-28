//Java
//Stacks as Linked Lists
public class StackNode {
	int value;
	StackNode down;
	public StackNode(int value) {
		this.value = value;
	}
}

import java.util.ArrayList;
import java.lang.*;
public class Stack {
	StackNode top;
	public boolean isEmpty() {
		return top == null;
	}
	
	public int peek() {
		return top.value;
	}
	
	public void push(int value) {
		if (top == null) {
			top = new StackNode(value);
			return;
		}
		StackNode newNode = new StackNode(value);
		newNode.down = top;
		top = newNode;
	}
	
	public void pop() {
		if (top == null) {
			return;
		}
		top = top.down;
	}
	
	public ArrayList<Integer> display() {
		ArrayList<Integer> rArr = new ArrayList<Integer>();
		StackNode current = top;
		while (current != null) {
			rArr.add(current.value);
			current = current.down;
		}
		return rArr;
	}

}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		Stack s = new Stack();
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



// Stacks as Arrays
import java.util.ArrayList;
import java.lang.*;
public class Stack {
	int[] stack;
	int topIndex;
	public Stack(int length) {
		stack = new int[length];
		topIndex = 0;
	}
	public boolean isEmpty() {
		return topIndex == 0;
	}
	
	public int peek() {
		if (isEmpty()) {
			return -1;
		}
		return stack[topIndex-1];
	}
	
	public void push(int value) {
		if (topIndex > stack.length-1) {
			return;
		}
		
		stack[topIndex] = value;
		topIndex++;
		return;
	}
	
	public void pop() {
		if (isEmpty()) {
			return;
		}
		topIndex = topIndex - 1;
		
	}
	
	public int[] display() {
		int[] rArr = new int[topIndex];
		int counter = 0;
		for (int i = topIndex-1; i > -1; i--) {
			rArr[counter] = stack[i];
			counter++;
		}
		return rArr;
	}
}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		Stack s = new Stack(5);
		System.out.println(s.isEmpty());
		s.push(0);
		s.push(1);
		s.push(2);
		s.push(3);
		s.pop();
		printS(s.display());
		System.out.println("Top: " + s.peek());
	}
}




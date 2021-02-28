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





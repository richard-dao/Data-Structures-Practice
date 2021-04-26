//Java
// LinkedList<Map> Chaining Resolution for Collisions
public class LinkedListMap {
	class LLMNode{
		LLMNode next;
		String key;
		int value;
		public LLMNode (String key, int value) {
			this.key = key;
			this.value = value;
		}
	}
	
	LLMNode head;
	public void prepend(String key, int value) {
		if (head == null) {
			head = new LLMNode(key, value);
			return;
		}
		LLMNode tempHead = head;
		head = new LLMNode(key, value);
		head.next = tempHead;
	}
	
	public void delete(String key) {
		if (head == null) {
			return;
		}
		if (head.key.equals(key)) {
			head = head.next;
			return;
		}
		
		LLMNode current = head;
		while (current != null && !(current.next.key.equals(key))) {
			current = current.next;
		}
		current.next = current.next.next;
	}
	
	public int findValue(String key) {
		LLMNode current = head;
		while (current != null && !(current.key.equals(key))) {
			current = current.next;
		}
		
		if (current == null) {
			return -1;
		}
		
		return current.value;
	}
	
	public void print() {
		LLMNode current = head;
		if (current == null) {
			return;
		}
		System.out.print("{");
		while (current != null) {
			int i = current.value;
			String s = Integer.toString(i);
			
			System.out.print("[" + current.key + " : " + s + "]");
			current = current.next;
		}
		System.out.println("}");
	}
	
	public LLMNode getHead() {
		if (head == null) {
			return null;
		}
		return head;
	}
}

import java.util.*;
public class HashMap {
	LinkedListMap[] hashmap;
	int size;
	public HashMap(int size) {
		this.size = size;
		hashmap = new LinkedListMap[size];
	}
	
	public int hash(String str) {
		// djb2
		int hash = 0;
		int leftShiftValue = 1;
		
		for (int i = 0; i < 2; i++) {
			if (str.length() > i) {
				hash = str.charAt(i) + ((hash << leftShiftValue) - hash);
			}
		}
		return hash;
	}
	
	public void add(String key, int value) {
		int index = hash(key);
		if (hashmap[index] == null) {
			hashmap[index] = new LinkedListMap();
		}
		if (hashmap[index].findValue(key) != -1) {
			return;
		}
		hashmap[index].prepend(key, value);
	}
	
	public void delete(String key) {
		int index = hash(key);
		if (hashmap[index] == null) {
			return;
		}
		hashmap[index].delete(key);
	}
	
	public int get(String key) {
		int index = hash(key);
		return hashmap[index].findValue(key);
	}
	
	public void print() {
		for (int i = 0; i < size; i++) {
			if (hashmap[i] != null) {
				hashmap[i].print();
			}
		}
	}
}

import java.util.ArrayList;
import java.util.LinkedList;

import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		HashMap h = new HashMap(253); // Size of Hashmap = 1 + (largest possible ASCII character value * (1 + leftShiftValue))
		h.add("Hlavac", 735);
		h.add("Strong", 145);
		h.add("Dao", 984);
		h.add("Dao", 118);
		h.add("Dang", 567);
		System.out.println(h.get("Dao"));
		h.print();
		h.delete("Strong");
		h.delete("Strong");
		h.print();
		h.add("A", 123);
		h.add("", 456);
		h.add("%", 789);
		h.add("~~", 005);
		h.print();
  }
}

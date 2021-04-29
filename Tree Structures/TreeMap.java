
public class TreeMapNode {
	TreeMapNode left;
	TreeMapNode right;
	String key;
	int value;
	public TreeMapNode(String key, int value) {
		this.key = key;
		this.value = value;
	}

}


public class TreeMap {
	TreeMapNode root;
	public TreeMapNode getRoot() {
		return root;
	}
	
	public void insert(TreeMapNode current, String key, int value) {
		if (root == current) {
			if (findLevel(root, key, 0) != -1) {
				return;
			}
		}
		if (root == null) {
			root = new TreeMapNode(key, value);
			return;
		}
		
		if (current == null) {
			return;
		}
		else if (key.compareTo(current.key) < 0) {
			if (current.left == null) {
				current.left = new TreeMapNode(key, value);
				return;
			}
			insert(current.left, key, value);
		}
		else if (key.compareTo(current.key) > 0) {
			if (current.right == null) {
				current.right = new TreeMapNode(key, value);
				return;
			}
			insert(current.right, key, value);
		}
		
	}
	
	public void deleteNode(String key) {
		root = delete(root, key);
		
	}
	
	public TreeMapNode delete(TreeMapNode current, String key) {
		if (current == null) {
			return current;
		}
		else if (key.compareTo(current.key) < 0) {
			current.left = delete(current.left, key);
		}
		else if (key.compareTo(current.key) > 0) {
			current.right = delete(current.right, key);
		}
		else {
			// 0 Children
			if (current.right == null && current.left == null) {
				current = null;
			}
			// 1 Child
			else if (current.left == null) {
				current = current.right;
			}
			else if (current.right == null) {
				current = current.left;
			}
			// 2 Children
			else{
				TreeMapNode temp = findMin(current.right);
				current.key = temp.key;
				current.value = temp.value;
				current.right = delete(current.right, temp.key);
			}
		}
		return current;
	}
	
	public TreeMapNode findMin(TreeMapNode current) {
		if (current.left != null) {
			return findMin(current.left);
		}

		return current;
	}
	
	public TreeMapNode findMax(TreeMapNode current) {
		if (current.right != null) {
			return findMax(current.right);
		}
		return current;
		
	}
	
	public int findLevel(TreeMapNode current, String key, int counter) {
		if (root == null) {
			return -1;
		}
		if (current == null) {
			return -1;
		}
		else if (key.compareTo(current.key) < 0) {
			return findLevel(current.left, key, counter+1);
		}
		else if (key.compareTo(current.key) > 0) {
			return findLevel(current.right, key, counter+1);
		}
		else if (key.compareTo(current.key) == 0) {
			return counter;
		}
		return -1;
	}
	
	public int find(TreeMapNode current, String key) {
		if (root == null || current == null) {
			return -1;
		}
		else if (key.compareTo(current.key) < 0) {
			return find(current.left, key);
		}
		else if (key.compareTo(current.key) > 0) {
			return find(current.right, key);
		}
		else if (key.compareTo(current.key) == 0) {
			return current.value;
		}
		return -1;
	}
	
	public void reverse(TreeMapNode current) {
		if (current != null) {
			TreeMapNode temp = current.right;
			current.right = current.left;
			current.left = temp;
			
			reverse(current.left);
			reverse(current.right);
		}
		
	}
	
	public int numberOfLeaves(TreeMapNode current, int counter) {
		if (current == null) {
			return counter;
		}
		if (current.left == null && current.right == null) {
			return numberOfLeaves(current.left, counter + 1);
		}
		return numberOfLeaves(current.left, counter) + numberOfLeaves(current.right, counter);
	}
	
	public void print(String input) {
		if (input.equalsIgnoreCase("Post Order")) {
			System.out.print("{");
			printPostOrder(root);
			System.out.println("}");
		}
		else if (input.equalsIgnoreCase("Pre Order")) {
			System.out.print("{");
			printPreOrder(root);
			System.out.println("}");
		}
		else {
			System.out.print("{");
			printInOrder(root);
			System.out.println("}");
		}
	}
	
	public void printInOrder(TreeMapNode current) {
		if (current == null) {
			return;
		}
		printInOrder(current.left);
		System.out.print("[" + current.key + " : " + Integer.toString(current.value) + "]");
		printInOrder(current.right);
	}
	
	public void printPreOrder(TreeMapNode current) {
		if (current == null) {
			return;
		}
		System.out.print("[" + current.key + " : " + Integer.toString(current.value) + "]");
		printPreOrder(current.left);
		printPreOrder(current.right);
	}
	
	public void printPostOrder(TreeMapNode current) {
		if (current == null) {
			return;
		}
		printPostOrder(current.left);
		printPostOrder(current.right);
		System.out.print("[" + current.key + " : " + Integer.toString(current.value) + "]");
	}

}

import java.util.*;

public class main {
	public static void main(String[] args) {
		TreeMap t = new TreeMap();
		t.insert(t.getRoot(), "Hlavac", 735);
		t.insert(t.getRoot(), "Dao", 984);
		t.insert(t.getRoot(), "Strong", 145);
		t.insert(t.getRoot(), "Dao", 510);
		t.insert(t.getRoot(), "Bonet", 754);
		t.print("In Order");
		t.deleteNode("Dao");
		t.print("in order");
		t.insert(t.getRoot(), "Dao", 510);
		System.out.println(t.find(t.getRoot(), "Bonet"));
		t.reverse(t.getRoot());
		t.print("in Order");
		t.print("post order");
		t.print("pre order");
		System.out.println(t.numberOfLeaves(t.getRoot(), 0));

		// (Tree before Reverse)
		// 		Hlavac
		//   Dao     Strong
		// Bonet
  }
}

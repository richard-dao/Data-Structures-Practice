//Java

public class TreeNode {
	TreeNode left;
	TreeNode right;
	int value;
	public TreeNode(int value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}

}

import java.util.ArrayList;
public class BinarySearchTree {
		TreeNode root;
	public int insert(TreeNode current, int value) {
		if (root == null) {
			root = new TreeNode(value);
			return 1;
		}
		if (find(root, value, 0) != -1) {
			return -1;
		}
		if (current.value < value) {
			if (current.right == null) {
				current.right = new TreeNode(value);
				return 1;
			}
			return insert(current.right, value);
		}
		if(current.value > value) {
			if (current.left == null) {
				current.left = new TreeNode(value);
				return 1;
			}
			return insert(current.left, value);
		}
		return 0;
	}
	
	public TreeNode getRoot() {
		return root;
	}
	
	public void deleteNode(int value) {
		root = delete(root, value);
	}
	
	public TreeNode delete(TreeNode current, int value) {
		if (current == null) {
			return current;
		}
		else if (value > current.value) {
			current.right = delete(current.right, value);
		}
		else if (value < current.value) {
			current.left = delete(current.left, value);
		}
		else {
			// Case 1: If there are no children (If it's a leaf)
			if (current.left == null && current.right == null) {
				current = null;
			}
			// Case 2: If there is 1 child
			else if (current.left == null) {
				current = current.right;
			}
			else if (current.right == null) {
				current = current.left;
			}
			// Case 3: If there are 2 children (Hibbard Deletion)
			else {
				TreeNode temp = findMin(current.right);
				current.value = temp.value;
				current.right = delete(current.right, temp.value);
			}
		}
		return current;
	
	}
	
	public TreeNode findMin(TreeNode current) {
		if (current.left == null) {
			return current;
		}
		return findMin(current.left);
	}
	
	public TreeNode findMax(TreeNode current) {
		if (current.right == null) {
			return current;
		}
		return findMax(current.right);
	}
	
	
	public int find(TreeNode current, int value, int counter) {
		if (root == null) {
			return -1;
		}
		if (current == null) {
			return -1;
		}
		if (current.value == value) {
			return counter;
		}
		if (current.value > value) {
			return find(current.left, value, counter+1);
		}
		if (current.value < value) {
			return find(current.right, value, counter+1);
		}
		return -1;
	}
	
	
	public void reverse(TreeNode current) {
		if (current == null) {
			return;
		}
		TreeNode temp = current.left;
		reverse(current.left);
		current.left = current.right;
		
		reverse(current.left);
		current.right = temp;
		
	}
	public void printInOrder(TreeNode current) {
		if (current == null) {
			return;
		}
		printInOrder(current.left); // 1
		System.out.print(current.value + ", "); // 2 
		printInOrder(current.right); // 3
	}
	
	public void printPreOrder(TreeNode current) {
		if (current == null) {
			return;
		}
		System.out.print(current.value + ", "); // 2
		printPreOrder(current.left); // 1
		printPreOrder(current.right); // 3
	}
	
	public void printPostOrder(TreeNode current) {
		if (current == null) {
			return;
		}
		printPostOrder(current.left); // 1
		printPostOrder(current.right); // 3
		System.out.print(current.value + ", "); // 2
	}

	
}

import java.util.ArrayList;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		BinarySearchTree b = new BinarySearchTree();
		
		b.insert(b.getRoot(), 1);
		b.insert(b.getRoot(), 3);
		b.insert(b.getRoot(), -2);
		b.insert(b.getRoot(), -3);
		b.insert(b.getRoot(), -1);
		b.insert(b.getRoot(), 4);
		b.insert(b.getRoot(), 2);
		b.insert(b.getRoot(), 0);
		b.insert(b.getRoot(), -4);
		b.insert(b.getRoot(), -5);
		/*
		 *        1
		 *    -2    3
		 *  -3 -1   2 4  
		 * -4     0
		 * -5
		 */
		
		
		
		System.out.println(b.find(b.getRoot(), -5, 0));
		b.printInOrder(b.getRoot()); // -3, -2, -1, 1, 3
		System.out.println();
		b.deleteNode(1);
		System.out.println(b.getRoot().value);
		b.printInOrder(b.getRoot());
		b.reverse(b.getRoot());
		System.out.println();
		b.printInOrder(b.getRoot());
		
		System.out.println();
		//b.printPreOrder(b.getRoot()); // 1, -2, -3, -1, 3
		System.out.println();
		//b.printPostOrder(b.getRoot()); // -3, -1, -2, 3, 1
  }
}

//Node.hpp
struct Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node(int val);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
Node::Node(int val){
    value = val;
    left = NULL;
    right = NULL;
}

//BST.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;

class BST{
    public:
        Node* root;
        BST();
        int insert(Node* current, int value);
        Node* getRoot();
        void deleteNode(int value);
        Node* deleteN(Node* current, int value);
        Node* findMin(Node* current);
        Node* findMax(Node* current);
        int find(Node* current, int value, int counter);
        void reverse(Node* current);
        void printInOrder(Node* current);
        void printPreOrder(Node* current);
        void printPostOrder(Node* current);

};

//BST.cpp
#include "BST.hpp"
#include <iostream>
using namespace std;

BST::BST(){
    root = NULL;
}

int BST::insert(Node* current, int value){
    if (root == NULL){
        root = new Node(value);
        return 1;
    }
    if (find(root, value, 0) != -1){
        return -1;
    }
    if (current->value < value){
        if (current->right == NULL){
            current->right = new Node(value);
            return 1;
        }
        return insert(current->right, value);
    }
    if (current->value > value){
        if (current->left == NULL){
            current->left = new Node(value);
            return 1;
        }
        return insert(current->left, value);
    }
    return 0;
}

Node* BST::getRoot(){
    return root;
}

void BST::deleteNode(int value){
    root = deleteN(root, value);
}

Node* BST::deleteN(Node* current, int value){
    if (current == NULL){
        return current;
    }
    else if (value > current->value){
        current->right = deleteN(current->right, value);
    }
    else if (value < current->value){
        current->left = deleteN(current->left, value);
    }
    else {
        if (current->left == NULL && current->right == NULL){
            current = NULL;
        }
        else if (current->left == NULL){
            current = current->right;
        }
        else if (current->right == NULL){
            current = current->left;
        }
        else{
            Node* temp = findMin(current->right);
            current->value = temp->value;
            current->right = deleteN(current->right, temp->value);
        }
    }
    return current;
}

Node* BST::findMin(Node* current){
    if (current->left == NULL){
        return current;
    }
    return findMin(current->left);
}

Node* BST::findMax(Node* current){
    if (current->right == NULL){
        return current;
    }
    return findMax(current->right);
}

int BST::find(Node* current, int value, int counter){
    if (root == NULL){
        return -1;
    }
    if (current == NULL){
        return -1;
    }
    if (current->value == value){
        return counter;
    }
    if (current->value > value){
        return find(current->left, value, counter+1);
    }
    if (current->value < value){
        return find(current->right, value, counter+1);
    }
    return -1;
}

void BST::reverse(Node* current){
    if (current != NULL){
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        
        reverse(current->left);
        reverse(current->right);
    }
}

void BST::printInOrder(Node* current){
    if (current == NULL){
        return;
    }
    printInOrder(current->left);
    std::cout << current->value << ", ";
    printInOrder(current->right);
}

void BST::printPreOrder(Node* current){
    if (current == NULL){
        return;
    }
    std::cout << current->value << ", ";
    printPreOrder(current->left);
    printPreOrder(current->right);
}

void BST::printPostOrder(Node* current){
    if (current == NULL){
        return;
    }
    printPostOrder(current->left);
    printPostOrder(current->right);
    std::cout << current->value << ", ";
}

//main.cpp
#include <iostream>
#include "BST.cpp"
using namespace std;

void printList(){
    std::vector<int> ll;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << " -> ";
    }
    std::cout << "\n";

}

int main(){
    BST b;
		
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
	std::cout << b.find(b.getRoot(), -5, 0) << "\n";
    b.printInOrder(b.getRoot());
    std::cout << "\n";
    b.deleteNode(1);
    std::cout << b.getRoot()->value << "\n";
    b.printInOrder(b.getRoot());
    b.reverse(b.getRoot());
    std::cout << "\n";
    b.printInOrder(b.getRoot());

    std::cout << "\n";
    b.printPreOrder(b.getRoot());
    std::cout << "\n";
    b.printPostOrder(b.getRoot());
    std::cout << "\n";
    
}

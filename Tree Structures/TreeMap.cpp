//Node.hpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{
    public:
        Node(std::string k, int val);
        std::string key;
        int value;
        Node* left;
        Node* right;
};

//Node.cpp
#include <iostream>
#include <vector>
#include <string>
#include "Node.hpp"
using namespace std;
Node::Node(std::string k, int val){
    key = k;
    value = val;
    left = NULL;
    right = NULL;
}

//TreeMap.hpp
#include <iostream>
#include <vector>
#include <string>
#include "Node.cpp"
using namespace std;

class TreeMap{
    public:
        Node* root;
        TreeMap();
        Node* getRoot();
        void insert(Node* current, std::string key, int value);
        void deleteNode(std::string key);
        Node* deleteN(Node* current, std::string key);
        Node* findMin(Node* current);
        Node* findMax(Node* current);
        int findLevel(Node* current, std::string key, int counter);
        int find(Node* current, std::string key);
        void reverse(Node* current);
        int numberOfLeaves(Node* current, int counter);
        void print(std::string input);
        void printInOrder(Node* current);
        void printPreOrder(Node* current);
        void printPostOrder(Node* current);
};


//TreeMap.cpp
#include <iostream>
#include <vector>
#include <string>
#include "TreeMap.hpp"
using namespace std;

TreeMap::TreeMap(){
    root = NULL;
}

Node* TreeMap::getRoot(){
    return root;
}

void TreeMap::insert(Node* current, std::string key, int value){
    if (root == current){
        if (findLevel(root, key, 0) != -1){
            return;
        }
    }
    if (root == NULL){
        root = new Node(key, value);
    }

    if (current == NULL){
        return;
    }
    else if (key.compare(current->key) < 0){
        if (current->left == NULL){
            current->left = new Node(key, value);
            return;
        }
        insert(current->left, key, value);
    }
    else if (key.compare(current->key) > 0){
        if (current->right == NULL){
            current->right = new Node(key, value);
            return;
        }
        insert(current->right, key, value);
    }

}

void TreeMap::deleteNode(std::string key){
    root = deleteN(root, key);
}

Node* TreeMap::deleteN(Node* current, std::string key){
    if (current == NULL){
        return current;
    }
    else if (key.compare(current->key) < 0){
        current->left = deleteN(current->left, key);
    }
    else if (key.compare(current->key) > 0){
        current->right = deleteN(current->right, key);
    }
    else{
        if (current->right == NULL && current->left == NULL){
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
            current->key = temp->key;
            current->value = temp->value;
            current->right = deleteN(current->right, temp->key);
        }
    }
    return current;
}

Node* TreeMap::findMin(Node* current){
    if (current->left != NULL){
        return findMin(current->left);
    }
    return current;
}

Node* TreeMap::findMax(Node* current){
    if (current->right != NULL){
        return findMax(current->right);
    }
    return current;
}

int TreeMap::findLevel(Node* current, std::string key, int counter){
    if (root == NULL){
        return -1;
    }
    if (current == NULL){
        return -1;
    }
    else if (key.compare(current->key) < 0){
        return findLevel(current->left, key, counter+1);
    }
    else if (key.compare(current->key) > 0){
        return findLevel(current->right, key, counter+1);
    }
    else if (key.compare(current->key) == 0){
        return counter;
    }
    return -1;
}

int TreeMap::find(Node* current, std::string key){
    if (root == NULL || current == NULL){
        return -1;
    }
    else if (key.compare(current->key) < 0){
        return find(current->left, key);
    }
    else if (key.compare(current->key) > 0){
        return find(current->right, key);
    }
    else if (key.compare(current->key) == 0){
        return current->value;
    }
    return -1;
}

void TreeMap::reverse(Node* current){
    if (current != NULL){
        Node* temp = current->right;
        current->right = current->left;
        current->left = temp;
        reverse(current->left);
        reverse(current->right);
    }
}

int TreeMap::numberOfLeaves(Node* current, int counter){
    if (current == NULL){
        return counter;
    }
    if (current->left == NULL && current->right == NULL){
        return numberOfLeaves(current->left, counter + 1);
    }
    return numberOfLeaves(current->left, counter) + numberOfLeaves(current->right, counter);
}

void TreeMap::print(std::string input){
    if (input == "Post Order"){
        std::cout << "{";
        printPostOrder(root);
        std:: cout << "}\n";
    }
    else if (input == "Pre Order"){
        std::cout << "{";
        printPreOrder(root);
        std::cout << "}\n";
    }
    else {
        std::cout << "{";
        printInOrder(root);
        std::cout << "} \n";
    }
}

void TreeMap::printInOrder(Node* current){
    if (current == NULL){
        return;
    }
    printInOrder(current->left);
    std::cout << "[" + current->key + " : " + std::to_string(current->value) + "]";
    printInOrder(current->right);
}

void TreeMap::printPreOrder(Node* current){
    if (current == NULL){
        return;
    }
    std::cout << "[" + current->key + " : " + std::to_string(current->value) + "]";
    printPreOrder(current->left);
    printPreOrder(current->right);
}

void TreeMap::printPostOrder(Node* current){
    if (current == NULL){
        return;
    }
    printPostOrder(current->left);
    printPostOrder(current->right);
    std::cout << "[" + current->key + " : " + std::to_string(current->value) + "]";
    
}

//main.cpp
#include <iostream>
#include <vector>
#include <string>
#include "TreeMap.cpp"
using namespace std;

int main(){
    TreeMap t;
    t.insert(t.getRoot(), "Hlavac", 735);
		t.insert(t.getRoot(), "Dao", 984);
		t.insert(t.getRoot(), "Strong", 145);
		t.insert(t.getRoot(), "Dao", 510);
		t.insert(t.getRoot(), "Bonet", 754);
		t.print("In Order");
		t.deleteNode("Dao");
		t.print("In order");
		t.insert(t.getRoot(), "Dao", 510);
		std::cout << (t.find(t.getRoot(), "Bonet")) << "\n";
		t.reverse(t.getRoot());
		t.print("In Order");
		t.print("Post Order");
		t.print("Pre Order");
		std::cout << (t.numberOfLeaves(t.getRoot(), 0));
}

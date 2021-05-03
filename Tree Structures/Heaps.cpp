//Node.hpp
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int val);
};

//Node.cpp
#include "Node.hpp"
#include <iostream>
#include <vector>

using namespace std;

Node::Node(int val){
    value = val;
    left = NULL;
    right = NULL;
}

//MinHeap.hpp
#include <iostream>
#include "Node.cpp"
#include <vector>
using namespace std;

class MinHeap{
    public:
        int size;
        int maxSize;
        std::vector<int> heap;
        MinHeap(int max);
        int getLeftChildIndex(int parentIndex);
        int getRightChildIndex(int parentIndex);
        int getParentIndex(int childIndex);

        bool hasLeftChild(int index);
        bool hasRightChild(int index);
        bool hasParent(int index);

        int leftChild(int index);
        int rightChild(int index);
        int parent(int index);

        void expandArr();
        bool isEmpty();
        int peek();
        int poll();
        void add(int value);
        void heapifyDown();
        void heapifyUp();
        void swap(int index1, int index2);
        void display();
        std::vector<int> getHeap();
        int height();
};

//MinHeap.cpp
#include "MinHeap.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

MinHeap::MinHeap(int max){
    maxSize = max;
    std::vector<int> temp(max);
    heap = temp;
    size = 0;
}

int MinHeap::getLeftChildIndex(int parentIndex){
    return (2 * parentIndex) + 1;
}

int MinHeap::getRightChildIndex(int parentIndex){
    return (2 * parentIndex) + 1;
}

int MinHeap::getParentIndex(int childIndex){
    return (childIndex - 1)/2;
}

bool MinHeap::hasLeftChild(int index){
    if (getLeftChildIndex(index) > size){
        return false;
    }
    return true;
}

bool MinHeap::hasRightChild(int index){
    if (getRightChildIndex(index) > size){
        return false;
    }
    return true;
}

bool MinHeap::hasParent(int index){
    if (index > size || index == 0){
        return false;
    }
    return true;
}

int MinHeap::leftChild(int index){
    return heap[getLeftChildIndex(index)];
}

int MinHeap::rightChild(int index){
    return heap[getRightChildIndex(index)];
}

int MinHeap::parent(int index){
    return heap[getParentIndex(index)];
}

void MinHeap::expandArr(){
    if (size == maxSize){
        std::vector<int> newHeap(maxSize*2);
        for (int i = 0; i < heap.size(); i++){
            newHeap[i] = heap[i];
        }
        maxSize = maxSize * 2;
        heap = newHeap;
    }
}

bool MinHeap::isEmpty(){
    return size == 0;
}

int MinHeap::peek(){
    if (isEmpty()){
        return -9999;
    }
    return heap[0];
}

int MinHeap::poll(){
    if (isEmpty()){
        return -9999;
    }
    int temp = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown();
    return temp;
}

void MinHeap::add(int value){
    expandArr();
    heap[size] = value;
    size++;
    heapifyUp();
}

void MinHeap::heapifyDown(){
    int i = 0;
    while (hasLeftChild(i)){
        int smallestIndex = getLeftChildIndex(i);
        if (hasRightChild(i) && (rightChild(i) < leftChild(i))){
            smallestIndex = getRightChildIndex(i);
        }
        if (heap[i] < heap[smallestIndex]){
            return;
        }
        else{
            swap(i, smallestIndex);
        }
        i = smallestIndex;
    }
}

void MinHeap::heapifyUp(){
    int i = size-1;
    while(hasParent(i)){
        if (parent(i) > heap[i]){
            swap(getParentIndex(i), i);
        }
        else{
            return;
        }
        i = getParentIndex(i);
    }
}

void MinHeap::swap(int index1, int index2){
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void MinHeap::display(){
    std::cout << "[";
    for (int i = 0; i < size; i++){
        std::cout << heap[i];
        if (i != size-1){
            std::cout << ", ";
        }
    }
    std::cout << "] \n";
}

std::vector<int> MinHeap::getHeap(){
    std::vector<int> rArr(size);
    for (int i = 0; i < size; i++){
        rArr[i] = heap[i];
    }
    return rArr;
}

int MinHeap::height(){
    return 1 + (int) (log(size) / log(2));
}

//MinHeapTree.hpp
#include <iostream>
#include <vector>
#include "MinHeap.cpp"

using namespace std;

class MinHeapTree{
    public:
        Node* root;
        MinHeapTree();
        Node* convertArrToTree(std::vector<int> heap, Node* current, int i);
        void printInOrder(Node* current);
        void printLevelOrder(int height);
        void printLevel(Node* current, int level);
};

//MinHeapTree.cpp
#include "MinHeapTree.hpp"
#include <iostream>
#include <vector>

using namespace std;

MinHeapTree::MinHeapTree(){
    root = NULL;
}

Node* MinHeapTree::convertArrToTree(std::vector<int> heap, Node* current, int i){
    if (i < heap.size()){
        Node* temp = new Node(heap[i]);
        current = temp;

        current->left = convertArrToTree(heap, current->left, 2*i + 1);
        current->right = convertArrToTree(heap, current->right, 2*i + 2);
    }
    return current;
}

void MinHeapTree::printInOrder(Node* current){
    if (current == NULL){
        return;
    }
    printInOrder(current->left);
    std::cout << current->value << ", ";
    printInOrder(current->right);
}

void MinHeapTree::printLevelOrder(int height){
    int i;
    std::cout << "[ ";
    for (int i = 0; i <= height; i++){
        printLevel(root, i);
    }
    std::cout << "] \n";
}

void MinHeapTree::printLevel(Node* current, int level){
    if (current == NULL){
        return;
    }
    if (level == 1){
        std::cout << current->value << " ";
    }
    else if (level > 1){
        printLevel(current->left, level-1);
        printLevel(current->right, level-1);
    }
}

//main.cpp
#include <iostream>
#include "MinHeapTree.cpp"
#include <vector>

int main(){
    MinHeap h = MinHeap(10);
    h.add(0);
    h.add(1);
    h.add(2);
    h.add(3);
    h.add(4);
    h.add(5);
    h.add(6);
    h.add(7);
    std::cout << h.poll() << "\n";
    h.display();
    std::cout << h.height() << "\n";
    MinHeapTree mT;
    mT.root = mT.convertArrToTree(h.getHeap(), mT.root, 0);
    mT.printLevelOrder(h.height());
}

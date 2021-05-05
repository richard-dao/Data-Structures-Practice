//Node.hpp
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public:
        int value;
        int level;
        Node* next;
        Node(int val, int lvl);
};

//Node.cpp
#include "Node.hpp"
#include <iostream>
#include <vector>
using namespace std;

Node::Node(int val, int lvl){
    value = val;
    level = lvl;
    next = NULL;
}

//PriorityQueue.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue{
    public:
        Node* head;
        PriorityQueue();
        bool isEmpty();
        int peek();
        void enqueue(int value, int level);
        int dequeue();
        void display();
};

//PriorityQueue.cpp
#include "PriorityQueue.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

PriorityQueue::PriorityQueue(){
    head = NULL;
}

bool PriorityQueue::isEmpty(){
    return head == NULL;
}

int PriorityQueue::peek(){
    if (isEmpty()){
        return -999;
    }
    Node* current = head;
    Node* minNode = head;
    while (current != NULL){
        if (current->level < minNode->level){
            minNode = current;
        }
        current = current->next;
    }
    return minNode->value;
}

void PriorityQueue::enqueue(int value, int level){
    if (isEmpty()){
        head = new Node(value, level);
        return;
    }
    Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new Node(value, level);
}

int PriorityQueue::dequeue(){
    Node* current = head;
    Node* minNode = head;
    Node* prev = NULL;
    Node* prevMin = NULL;

    if (isEmpty()){
        return -999;
    }

    while (current != NULL){
        if (current->level < minNode->level){
            minNode = current;
            prevMin = prev;
        }
        prev = current;
        current = current->next;
    }
    if (minNode == head){
        head = head->next;
        if (head == NULL){
            return -999;
        }
        return head->value;
    }
    int value = minNode->value;
    prevMin->next = prevMin->next->next;
    return value;
}

void PriorityQueue::display(){
    Node* current = head;
    while (current != NULL){
        std::cout << "[" << to_string(current->value) << " : " << to_string(current->level) << "]\n";
        current = current->next; 
    }
}

//main.cpp
#include "PriorityQueue.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    PriorityQueue p;
    p.enqueue(9, 4);
    p.enqueue(10, 3);
    p.enqueue(13, 5);
    p.enqueue(10, 2);
    p.enqueue(8, 2);
    std::cout << p.peek() << "\n";
    p.dequeue();
    std::cout << p.peek() << "\n";
    p.display();   
}

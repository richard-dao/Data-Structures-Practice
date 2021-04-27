//Node.hpp
struct Node {
    public:
        int value;
        Node* next;
        Node(int val);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
using namespace std;
Node::Node(int val){
    value = val;
    next = NULL;
}

//Queue.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Queue{
    public:
        Node* head;
        Node* tail;
        Queue();
        bool isEmpty();
        int peek();
        void push(int value);
        void pop();
        std::vector<int> display();
};

//Queue.cpp
#include "Queue.hpp"
#include <iostream>
using namespace std;

Queue::Queue(){
    head = NULL;
    tail = NULL;
}

bool Queue::isEmpty(){
    return head == NULL;
}

int Queue::peek(){
    return head->value;
}

void Queue::push(int value){
    Node* newNode = new Node(value);
    if (isEmpty()){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void Queue::pop(){
    if (isEmpty()){
        return;
    }
    if (head->next == NULL){
        head = NULL;
        tail = NULL;
        return;
    }
    head = head->next;
}

std::vector<int> Queue::display(){
    std::vector<int> rArr;
    Node* current = head;
    while (current != NULL){
        rArr.push_back(current->value);
        current = current->next;
    }
    return rArr;
}


//Queue.hpp as Array
#include <iostream>
#include <vector>
using namespace std;

class Queue{
    public:
        std::vector<int> queue;
        int headIndex;
        int tailIndex;
        Queue(int length);
        bool isEmpty();
        int peek();
        void push(int value);
        void pop();
        std::vector<int> display();
};

//Queue.cpp as Array
#include "Queue.hpp"
#include <iostream>
using namespace std;

Queue::Queue(int length){
    std::vector<int> temp(length);
    queue = temp;
    headIndex = 0;
    tailIndex = 0;
}

bool Queue::isEmpty(){
    return headIndex == tailIndex;
}

int Queue::peek(){
    if (isEmpty()){
        return -1;
    }
    return queue[headIndex];
}

void Queue::push(int value){
    queue[tailIndex] = value;
    tailIndex++;
    if(tailIndex > queue.size()){
        tailIndex = 0;
    }
    return;
}

void Queue::pop(){
    if (isEmpty()){
        return;
    }
    headIndex++;
    if (headIndex > queue.size()){
        headIndex = 0;
    }
}

std::vector<int> Queue::display(){
    std::vector<int> rArr;
    if (isEmpty()){
        return rArr;
    }
    if (tailIndex < headIndex){
        for (int i = headIndex; i < queue.size(); i++){
            rArr.push_back(queue[i]);
        }
        for (int i = 0; i < tailIndex; i++){
            rArr.push_back(queue[i]);
        }
    }
    else{
        for (int i = headIndex; i < tailIndex; i++){
            rArr.push_back(queue[i]);
        }
    }
    return rArr;
}

//main.cpp
#include <iostream>
#include "Queue.cpp"
using namespace std;

void printList(std::vector<int> l){
    for(int i = 0; i < l.size(); i++){
        std::cout << l[i] << " -> ";
    }
    std::cout << "\n";

}

int main(){
	Queue s;
	std::cout << s.isEmpty() << "\n";
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	printList(s.display());
	std::cout << "Top: " << s.peek() << "\n";
	
}

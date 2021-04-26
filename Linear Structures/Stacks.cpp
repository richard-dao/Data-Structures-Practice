//Node.hpp
struct Node {
    public:
        int value;
        Node* down;
        Node(int value);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
using namespace std;
Node::Node(int val){
    value = val;
    down = NULL;
}

//Stack.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
        Node* top;
        Stack();
        bool isEmpty();
        int peek();
        void push(int value);
        void pop();
        std::vector<int> display();

};

//Stack.cpp
#include "Stack.hpp"
#include <iostream>
using namespace std;
Stack::Stack(){
    top = NULL;
}

bool Stack::isEmpty(){
    return top == NULL;
}

int Stack::peek(){
    return top->value;
}

void Stack::push(int value){
    if (top == NULL){
        top = new Node(value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->down = top;
    top = newNode;
}

void Stack::pop(){
    if (top == NULL){
        return;
    }
    top = top->down;
}

std::vector<int> Stack::display(){
    std::vector<int> rArr;
    Node* current = top;
    while (current != NULL){
        rArr.push_back(current->value);
        current = current->down;
    }
    return rArr;
}



//Stack.hpp As Array
#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
        std::vector<int> stack;
        int topIndex;
        Stack(int length);
        bool isEmpty();
        int peek();
        void push(int value);
        void pop();
        std::vector<int> display();
};

//Stack.cpp as Array
#include "Stack.hpp"
#include <iostream>
using namespace std;
Stack::Stack(int length){
    std::vector<int> temp(length);
    stack = temp;
    topIndex = 0;
}

bool Stack::isEmpty(){
    return topIndex == 0;
}

int Stack::peek(){
    if (isEmpty()){
        return -1;
    }
    return stack[topIndex-1];
}

void Stack::push(int value){
    if (topIndex > stack.size() - 1){
        return;
    }
    stack[topIndex] = value;
    topIndex++;
    return;
}

void Stack::pop(){
    if(isEmpty()){
        return;
    }
    topIndex = topIndex-1;
}

std::vector<int> Stack::display(){
    std::vector<int> rArr(topIndex);
    int counter = 0;
    for (int i = topIndex-1; i > -1; i--){
        rArr[counter] = stack[i];
        counter++;
    }
    return rArr;
}


//main.cpp
#include <iostream>
#include "Stack.cpp"
using namespace std;

void printList(std::vector<int> l){
    for(int i = 0; i < l.size(); i++){
        std::cout << l[i] << " -> ";
    }
    std::cout << "\n";

}

int main(){
	Stack s;
	std::cout << s.isEmpty() << "\n";
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	printList(s.display());
	std::cout << "Top: " << s.peek() << "\n";
	
}

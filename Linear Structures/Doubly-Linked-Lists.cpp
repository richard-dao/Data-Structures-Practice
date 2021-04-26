// Node.hpp
struct Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int val);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
Node::Node(int val){
    value = val;
    next = NULL;
    prev = NULL;
}

//LinkedList.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;
class LinkedList{
    public:
        Node* head;
        LinkedList();
        Node* getHead();
        void setHead(Node* head);
        Node* getTail();
        void append(int value);
        void prepend(int value);
        void insert(int value, int position);
        void deleteFirst(int value);
        void deleteAt(int position);
        void deleteAll(int value);
        int getLength();
        vector<int> getValues();
        void reverse();
        Node* reverseRecursive(Node* current);
        
};

//LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
LinkedList::LinkedList(){
    head = NULL;
}
Node* LinkedList::getHead(){
    return head;
}

void LinkedList::setHead(Node* node){
    head = node;
}

Node* LinkedList::getTail(){
    Node* current = head;
    if (head == NULL){
        return head;
    }
    while (current->next != NULL){
        current = current->next;
    }
    return current;
}

void LinkedList::append(int value){
    Node* current = head;
    if (current == NULL){
        head = new Node(value);
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new Node(value);
    current->next->prev = current;
}

void LinkedList::prepend(int value){
    Node* current = head;
    if (current == NULL){
        head = new Node(value);
        return;
    }
    Node* newHead = new Node(value);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
}

void LinkedList::insert(int value, int position){
    Node* current = head;
    if (head == NULL){
        prepend(value);
        return;
    }
    if (position == 0){
        prepend(value);
        return;
    }
    int count = 0;
    while (count + 1 < position){
        current = current->next;
        count++;
    }
    if (current->next == NULL){
        append(value);
        return;
    }
    Node* inserted = new Node(value);
    Node* nextTemp = current->next;
    current->next = inserted;
    inserted->prev = current;
    inserted->next = nextTemp;
    nextTemp->prev = inserted;
}

void LinkedList::deleteFirst(int value){
    Node* current = head;
    if (head == NULL){
        return;
    }
    if (head->value == value){
        head = current->next;
        head->prev = NULL;
        return;
    }
    while (current->value != value && current != NULL){
        current = current->next;
    }
    if (current != NULL && current->next != NULL){
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    else if (current != NULL){
        current->prev->next = current->next;
    }
    else{
        return;
    }
    return;
}

void LinkedList::deleteAt(int position){
    Node* current = head;
    if (head == NULL){
        return;
    }
    if (position == 0 && head->next != NULL){
        Node* newHead = head->next;
        head = newHead;
        head->prev = NULL;
        return;
    }
    else if (position == 0){
        head = NULL;
        return;
    }
    int counter = 0;
    while (counter + 1 < position && current != NULL){
        current = current->next;
        counter++;
    }

    if (current == NULL){
        return;
    }
    else if (current->next == NULL){
        current->next = NULL;
    }
    else if (current->next->next == NULL){
        current->next = NULL;
    }
    else{
        current->next = current->next->next;
        current->next->prev = current;
    }
    return;
}

void LinkedList::deleteAll(int value){
    Node* current = head;
    if (head == NULL){
        return;
    }
    while (current != NULL){
        if (head->value == value && head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else if (head->value == value){
            head = NULL;
            return;
        }
        else if (current->value == value && current->next != NULL){
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        else if (current->value == value){
            current->prev->next = NULL;
        }
        current = current->next;

    }
}

int LinkedList::getLength(){
    int counter = 0;
    Node* current = head;
    while (current != NULL){
        current = current->next;
        counter++;
    }
    return counter;
}

std::vector<int> LinkedList::getValues(){
    std::vector<int> rArr;
    Node* current = head;
    for (int i = 0; i < getLength(); i++){
        rArr.push_back(current->value);
        current = current->next;
    }
    return rArr;
}

void LinkedList::reverse(){
    Node* current = head;
    Node* tempNext;

    if (head == NULL){
        return;
    }
    while (current != NULL){
        if (current->next == NULL){
            current->next = current->prev;
            current->prev = NULL;
            head = current;
            return;
        }
        tempNext = current->next;
        current->next = current->prev;
        current->prev = tempNext;
        current = tempNext;

    }
    head = current;
}

Node* LinkedList::reverseRecursive(Node* current){
    if (current->next == NULL){
        current->next = current->prev;
        current->prev = NULL;
        return current;
    }
    Node* tempNext = current->next;
    current->next = current->prev;
    current->prev = tempNext;
    return reverseRecursive(tempNext);
}

//main.cpp

#include <iostream>
#include "LinkedList.cpp"
using namespace std;

void printList(LinkedList list){
    std::vector<int> ll = list.getValues();
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << " -> ";
    }
    std::cout << "\n";

}

int main(){
    LinkedList l;
    l.prepend(1);
    l.prepend(0);
    l.append(2);
    l.append(1);
    l.append(2);
    l.insert(4,3);
    l.deleteFirst(2);
    l.append(3);
    l.deleteAt(4);
    l.append(1);
    l.append(1);
    l.deleteAll(1);
    l.reverse();
    l.setHead(l.reverseRecursive(l.getHead()));
    printList(l);

}

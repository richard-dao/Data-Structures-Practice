// Node.hpp
struct Node {
    public:
        int value;
        Node* next;
        Node(int val);
};

//Node.cpp
#include "Node.hpp"
#include <iostream>
Node::Node(int val){
    value = val;
    next = NULL;
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
        void append(int value);
        void prepend(int value);
        void deleteFirst(int value);
        void deleteAll(int value);
        int getLength();
        vector<int> getValues();
        void reverse();
        void insert(int value, int position);
};

//LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::append(int value){
    if (head == NULL){
        head = new Node(value);
        return;
    }
    Node* current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new Node(value);
}

void LinkedList::prepend(int value){
    Node* newHead = new Node(value);
    newHead->next = head;
    head = newHead;
}

void LinkedList::deleteFirst(int value){
    if (head == NULL){
        return;
    }
    if (head->value == value){
        head = head->next;
        return;
    }
    Node* current = head;
    while (current->next != NULL){
        if (current->next->value == value){
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
}

void LinkedList::deleteAll(int value){
    if (head == NULL){
        return;
    }
    Node* current = head;
    while (current->next != NULL){
        if (current->next->value == value){
            current->next = current->next->next;
        }
        else{
            current = current->next;
        }
    }
    if (head->value == value){
        head = head->next;
    }
}

int LinkedList::getLength(){
    if (head == NULL){
        return 0;
    }
    int count = 0;
    Node* current = head;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

std::vector<int> LinkedList::getValues(){
    Node* current = head;
    std::vector<int> rValues;

    if (head == NULL){
        return rValues;
    }
    while (current != NULL){
        rValues.push_back(current->value);
        current = current->next;
    }
    return rValues;
}

void LinkedList::reverse(){
    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::insert(int value, int position){
    int counter = 0;
    Node* current = head;
    if (counter == position){
        prepend(value);
        return;
    }
    else{
        while (counter + 1 < position && current->next != NULL){
            current = current->next;
            counter++;
        }
    }
    if (current->next == NULL){
        return;
    }
    Node* next = current->next;
    Node* inserted = new Node(value);
    current->next = inserted;
    inserted->next = next;
}

// main.cpp
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
    l.append(0);
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(0);
    printList(l);
    l.deleteAll(0);
    printList(l);
    l.prepend(1);
    printList(l);
    l.deleteAll(1);
    printList(l);
    l.prepend(0);
    printList(l);
    l.reverse();
    printList(l);
    l.reverse();
    printList(l);
    l.append(0);
    printList(l);
    l.deleteFirst(0);
    printList(l);
    l.insert(1, 1);
    printList(l);
    l.insert(9, 0);
    printList(l);
}

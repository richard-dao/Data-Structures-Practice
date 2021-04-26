// Node.hpp
struct Node {
    public:
        int value;
        Node* next;
        Node(int val);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
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
        Node* last;
        LinkedList();
        void append(int value);
        void prepend(int value);
        void insert(int value, int position);
        void deleteFirst(int value);
        void deleteAll(int value);
        void deleteAt(int position);
        int getLength();
        std::vector<int> getValues();
        void reverse();
        Node* getPrev();
        Node* reverseRecursive(Node* current, Node* previous, Node* stop);
        Node* getLast();
        void setLast(Node* newLast);
        
};

//LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
LinkedList::LinkedList(){
    last = NULL;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (last == NULL){
        last = newNode;
        last->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void LinkedList::prepend(int value){
    Node* newNode = new Node(value);
    if (last == NULL){
        last = newNode;
        last->next = last;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
}

void LinkedList::insert(int value, int position){
    Node* current = last->next;
    Node* newNode = new Node(value);
    int counter = 0;
    if (last == NULL || position == 0){
        append(value);
        return;
    }

    if (position > getLength()-1){
        append(value);
        return;
    }

    while (current->next != last && counter + 1 < position) {
        current = current->next;
        counter++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::deleteFirst(int value){
    Node* current = last;
    if (last == NULL){
        return;
    }
    while (current->next != last && current->next->value != value){
        current = current->next;
    }
    if (current->next->value != value){
        return;
    }
    else if (current->next != last){
        current->next = current->next->next;
    }
    else {
        Node* tempCurrent = last;
        if (last->value == value){
            if (last->next == last){
                last = NULL;
                return;
            }
            while (tempCurrent->next != last){
                tempCurrent = tempCurrent->next;
            }
            tempCurrent->next = tempCurrent->next->next;
            last = tempCurrent;
            return;
        }
    }
}

void LinkedList::deleteAll(int value){
    Node* current = last->next;
    if (last == NULL){
        return;
    }
    int counter = 0;
    while (current->next != last){
        if (current->value == value){
            counter++;
        }
        current = current->next;
    }
    if (last->value == value){
        counter = counter + 1;
    }
    for (int i = 0; i <= counter; i++){
        deleteFirst(value);
    }
}

void LinkedList::deleteAt(int position){
    if (last == NULL || position > getLength()-1){
        return;
    }
    if (last->next == last){
        if (position == 0){
            last = NULL;
            return;
        }
    }

    Node* current = last;
    int counter = 0;
    while (current->next != last && counter < position){
        current = current->next;
        counter++;
    }
    if (position == getLength()-1){
        current->next = last->next;
        last = current;
        return;
    }
    current->next = current->next->next;
}

int LinkedList::getLength(){
    Node* current = last;
    if (last == NULL){
        return 0;
    }
    int counter = 0;
    while (current->next != last){
        counter++;
        current = current->next;
    }
    return counter + 1;
}

std::vector<int> LinkedList::getValues(){
    Node* current = last;
    std::vector<int> rArr;
    if (last == NULL){
        return rArr;
    }
    for (int i = 0; i < getLength(); i++){
        current = current->next;
        rArr.push_back(current->value);
    }
    rArr[rArr.size()-1] = last->value;
    return rArr;
}

void LinkedList::reverse(){
    Node* prev = last;
    Node* current = last->next;
    Node* next;

    while (current != last){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    next = current->next;
    current->next = prev;
    prev = current;
    last = next;
}

Node* LinkedList::getPrev(){
    Node* current = last;
    while (current->next != last){
        current = current->next;
    }
    return current;
}

Node* LinkedList::reverseRecursive(Node* current, Node* previous, Node* stop){
    Node* next;
    if (current->next == stop){
        next = current->next;
        current->next = previous;
        return next;
    }
    next = current->next;
    current->next = previous;
    return reverseRecursive(next, current, stop);
}

Node* LinkedList::getLast(){
    return last;
}

void LinkedList::setLast(Node* newLast){
    last = newLast;
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
    l.append(0);
		l.append(1);
		l.append(2);
		l.append(3);
		l.append(3);
		l.prepend(-1);
		l.insert(9, 5);
		l.append(3);
		l.deleteFirst(3);
		l.append(3);
		l.append(3);
		l.deleteAll(3);
    
    printList(l);
    l.deleteAt(4);
    printList(l);
    l.reverse();
    printList(l);
    l.setLast(l.reverseRecursive(l.getLast()->next, l.getLast(), l.getLast()->next));
    printList(l);
}

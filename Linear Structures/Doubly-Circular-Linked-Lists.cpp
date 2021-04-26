//Node.hpp
struct Node {
    public:
        int value;
        Node* next;
        Node* prev;
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
        Node* last;
        LinkedList();
        std::vector<int> getValues();
        int getLength();
        void append(int value);
        void prepend(int value);
        void insert(int value, int position);
        void deleteFirst(int value);
        void deleteAll(int value);
        void deleteAt(int position);
        void reverse();
        void setLast(Node* newLast);
        Node* getLast();
        Node* reverseRecursive(Node* previous, Node* current, Node* stop);
        
};

//LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
LinkedList::LinkedList(){
    last = NULL;
}
std::vector<int> LinkedList::getValues(){
    std::vector<int> rArr;
    if (last == NULL){
        return rArr;
    }
    Node* current = last;
    for (int i = 0; i < getLength(); i++){
        rArr.push_back(current->next->value);
        current = current->next;
    }
    rArr[getLength()-1] = last->value;
    return rArr;
}

int LinkedList::getLength(){
    int counter = 0;
    Node* current = last;
    if (last == NULL){
        return 0;
    }
    while (current->next != last){
        counter++;
        current = current->next;
    }
    return counter + 1;
}

void LinkedList::append(int value){
    Node* newNode = new Node(value);
    if (last == NULL){
        last = newNode;
        last->prev = last;
        last->next = last;
        return;
    }
    newNode->prev = last;
    newNode->next = last->next;
    last->next->prev = newNode;
    last->next = newNode;
    last = newNode;
}

void LinkedList::prepend(int value){
    Node* newNode = new Node(value);
    if (last == NULL){
        append(value);
        return;
    }
    newNode->prev = last;
    newNode->next = last->next;
    last->next->prev = newNode;
    last->next = newNode;
}

void LinkedList::insert(int value, int position){
    if (last == NULL || position == 0){
        prepend(value);
        return;
    }
    if (position > getLength() -1){
        append(value);
        return;
    }
    Node* current = last->next;
    Node* newNode = new Node(value);
    int counter = 0;
    while (counter + 1 < position && current->next != last){
        current = current->next;
        counter++;
    }
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
}

void LinkedList::deleteFirst(int value){
    if (last == NULL){
        return;
    }
    if (last->next == last && last->value == value){
        last = NULL;
        return;
    }
    Node* current = last;
    while (current->next->value != value && current->next != last){
        current = current->next;
    }
    if (current->next == last && last->value == value){
        last->prev->next = last->next;
        last->next->prev = last->prev;
        last = last->prev;
        return;
    }
    else if (current->next == last){
        return;
    }
    else{
        current->next = current->next->next;
        current->next->prev = current;
    }
}

void LinkedList::deleteAll(int value){
    if (last == NULL){
        return;
    }
    Node* current = last->next;
    while (current != last){
        if (current->value == value){
            deleteFirst(value);
        }
        current = current->next;
    }
    deleteFirst(value);
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
    if (current->next == last){
        last->prev->next = last->next;
        last->next->prev = last->prev;
        last = last->prev;
        return;
    }
    current->next = current->next->next;
    current->next->prev = current;
}

void LinkedList::reverse(){
    if (last == NULL){
        return;
    }
    Node* previous = last;
    Node* current = last->next;
    Node* next;
    while (current != last){
        next = current->next;
        current->next = previous;
        current->prev = next;
        previous = current;
        current = next;
    }
    next = current->next;
    current->next = previous;
    current->prev = next;
    last = next;
}

void LinkedList::setLast(Node* newLast){
    last = newLast;
}

Node* LinkedList::getLast(){
    return last;
}

Node* LinkedList::reverseRecursive(Node* previous, Node* current, Node* stop){
    Node* next;
    if (current == stop){
        next = current->next;
        current->next = previous;
        current->prev = next;
        return next;
    }
    next = current->next;
    current->next = previous;
    current->prev = next;
    return reverseRecursive(current, next, stop);
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
		l.insert(2, 2);
		l.insert(3, 4);
		l.append(1);
		l.append(1);
		l.append(1);
		l.prepend(-1);
		l.deleteAll(1);
		l.deleteAt(1);
		l.reverse();
		l.setLast(l.reverseRecursive(l.getLast(), l.getLast()->next, l.getLast()));
        std::cout << l.getLength() << "\n";
        printList(l);
}

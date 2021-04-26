//Node.hpp
struct Node {
    public:
        int value;
        std::string key;
        Node* next;
        Node(std::string k, int val);
};

//Node.cpp
#include <iostream>
#include "Node.hpp"
using namespace std;
Node::Node(std::string k, int val){
    key = k;
    value = val;
    next = NULL;
}

//LinkedListMap.hpp
#include "Node.cpp"
#include <iostream>
#include <vector>
using namespace std;
class LinkedListMap{
    public:
        Node* head;
        LinkedListMap();
        void prepend(std::string key, int value);
        void deleteN(std::string key);
        int findValue(std::string key);
        void print();
        Node* getHead();
};

//LinkedListMap.cpp
#include <iostream>
#include "LinkedListMap.hpp"
using namespace std;

LinkedListMap::LinkedListMap(){
    head = NULL;
}

void LinkedListMap::prepend(std::string key, int value){
    if (head == NULL){
        head = new Node(key, value);
        return;
    }
    Node* tempHead = head;
    head = new Node(key, value);
    head->next = tempHead;
}

void LinkedListMap::deleteN(std::string key){
    if (head == NULL){
        return;
    }
    if (head->key == key){
        head = head->next;
        return;
    }
    Node* current = head;
    while (current != NULL && (current->next->key != key)){
        current = current->next;
    }
    current->next = current->next->next;
}

int LinkedListMap::findValue(std::string key){
    Node* current = head;
    while (current != NULL && (current->key != key)){
        current = current->next;
    }
    if (current == NULL){
        return -1;
    }
    return current->value;
}

void LinkedListMap::print(){
    Node* current = head;
    if (current == NULL){
        return;
    }
    std::cout << "{";
    while (current != NULL){
        int i = current->value;
        std::string s = std::to_string(i);
        std::cout << "[" << current->key << " : " << s << "]";
        current = current->next;
    }
    std::cout << "} \n";
}

Node* LinkedListMap::getHead(){
    if (head == NULL){
        return NULL;
    }
    return head;
}

//HashMap.hpp
#include "LinkedListMap.cpp"
using namespace std;
class HashMap{
    public:
        std::vector<LinkedListMap> hashmap;
        HashMap(int size);
        int hash(std::string str);
        void add(std::string key, int value);
        void deleteN(std::string key);
        int get(std::string key);
        void print();
};

//HashMap.cpp
#include "HashMap.hpp"
#include <iostream>
using namespace std;
HashMap::HashMap(int size){
    std::vector<LinkedListMap> s(size);
    hashmap = s;
}

int HashMap::hash(std::string str){
    int hash = 0;
    int leftShiftValue = 1;

    for (int i = 0; i < 2; i++){
        if (str.length() > i){
            hash = int(str.at(i)) + ((hash << leftShiftValue) - hash);
        }
    }
    return hash;
}

void HashMap::add(std::string key, int value){
    int index = hash(key);
    if (hashmap[index].head == NULL){
        LinkedListMap l;
        hashmap[index] = l;
    }
    if (hashmap[index].findValue(key) != -1){
        return;
    }
    hashmap[index].prepend(key, value);

}

void HashMap::deleteN(std::string key){
    int index = hash(key);
    if (hashmap[index].head == NULL){
        return;
    }
    hashmap[index].deleteN(key);
}

int HashMap::get(std::string key){
    int index = hash(key);
    return hashmap[index].findValue(key);
}

void HashMap::print(){
    for (int i = 0; i < hashmap.size(); i++){
        if (hashmap[i].head != NULL){
            hashmap[i].print();
        }
    }
}

//main.cpp
#include <iostream>
#include "HashMap.cpp"
using namespace std;

void printList(){
    std::vector<int> ll;
    for(int i = 0; i < ll.size(); i++){
        std::cout << ll[i] << " -> ";
    }
    std::cout << "\n";

}

int main(){
    HashMap h = HashMap(253);
    h.add("Hlavac", 735);
		h.add("Strong", 145);
		h.add("Dao", 984);
		h.add("Dao", 118);
		h.add("Dang", 567);
		std::cout << h.get("Dao") << "\n";
		h.print();
		h.deleteN("Strong");
		h.deleteN("Strong");
		h.print();
		h.add("A", 123);
		h.add("", 456);
		h.add("%", 789);
		h.add("~~", 5);
		h.print();
}

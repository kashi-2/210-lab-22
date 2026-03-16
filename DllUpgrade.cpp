// COMSC-210 | Doubly Linked List Upgrade | Akashdeep Singh

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {

private:

    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:

    // constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int value) {

        Node* newNode = new Node(value);

        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {

        Node* newNode = new Node(value);

        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // delete head node 
    void pop_front() {

        if (!head) return;

        Node* temp = head;

        if (head == tail)
            head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // delete tail node
    void pop_back() {

        if (!tail) return;

        Node* temp = tail;

        if (head == tail)
            head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // delete by value 
    void delete_val(int value) {

        if (!head) return;

        Node* temp = head;

        while (temp && temp->data != value) 
            temp = temp->next;

        if(!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        
        if (temp->next)
            temp->next->prev = temp->prev;
        else 
            tail = temp->prev;

        delete temp;
    } 

    // delete by position
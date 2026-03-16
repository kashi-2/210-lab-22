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
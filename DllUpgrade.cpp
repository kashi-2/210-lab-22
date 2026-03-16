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
    void delete_pos(int position) {

        if (!head) return;

        Node* temp = head;

        for (int i = 0; i < position && temp; i++) 
            temp = temp->next;

        if (!temp) return;

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

    void print() {

        Node* current = head;

        if (!current) {
            cout << "List empty\n";
            return;
        }

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    } 

    void print_reverse() {

        Node* current = tail;

        if (!current) {
            cout << "List empty\n";
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    ~DoublyLinkedList() {

        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    
    srand(time(0));

    DoublyLinkedList list;

    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS; 

    for (int i = 0; i < size; i++)
        list.push_back(rand() % (MAX_NR - MIN_NR +1) + MIN_NR);

    cout << "Initial list:\n";
    list.print();

    cout << "Reverse:\n";
    list.print_reverse();

    cout << "\nTesting pop_front()\n";
    list.pop_front();
    list.print();

    cout << "\nTesting pop_back()\n";
    list.pop_front();
}
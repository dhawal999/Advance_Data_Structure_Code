// filename: stack_linkedlist.cpp
// Compile: g++ stack_linkedlist.cpp -o stack
// Run: ./stack

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << top->data << endl;
        top = top->next;
    }
    void display() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}


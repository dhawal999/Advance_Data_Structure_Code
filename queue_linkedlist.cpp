// filename: queue_linkedlist.cpp
// Compile: g++ queue_linkedlist.cpp -o queue
// Run: ./queue

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() { front = rear = nullptr; }
    void enqueue(int x) {
        Node* temp = new Node{x, nullptr};
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr;
    }
    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

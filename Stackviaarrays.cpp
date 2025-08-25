#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack: [";
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
            if (i < top) cout << ",";
        }
        cout << "]\n";
    }

    ~Stack() {
        delete[] arr;
    }
};

class Queue {
    int* arr;
    int front, rear, capacity, count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: [";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity];
            if (i < count - 1) cout << ",";
        }
        cout << "]\n";
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    cout << "=== Stack Demo ===\n";
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element (peek): " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.display();
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();

    cout << "\n=== Queue Demo ===\n";
    Queue q(5);
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    cout << "Front element (peek): " << q.peek() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    q.enqueue(400);
    q.enqueue(500);
    q.enqueue(600);
    q.display();

    return 0;
}

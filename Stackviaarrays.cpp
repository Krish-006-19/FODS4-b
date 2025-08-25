#include <iostream>
using namespace std;

class Stack {
    int* arr;     // array to store elements
    int top;      // index of top element
    int capacity; // maximum size

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
        cout << "[";
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

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // [10,20,30]

    cout << "Top element (peek): " << s.peek() << endl; // 30
    cout << "Popped: " << s.pop() << endl;             // removes 30
    s.display(); // [10,20]

    s.push(40);
    s.push(50);
    s.push(60); // stack full
    s.display(); // [10,20,40,50,60]

    return 0;
}

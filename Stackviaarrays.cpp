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
    s.display();  

    cout << "Top element (peek): " << s.peek() << endl; 
    cout << "Popped: " << s.pop() << endl;            
    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.display(); 

    return 0;
}

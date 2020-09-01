#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int capacity;
    int* data;
    int top; // index of the last element
public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->data = new int[capacity];
        top = -1;
    }

    void copyStack(const Stack& rhs) {
        this->capacity = rhs.capacity;
        this->data = new int[capacity];
        this->top = rhs.top;
        for (int i = 0; i <= rhs.top; i++) {
            this->data[i] = rhs.data[i];
        }
    }

    void freeMemory() {
        delete[] this->data;
        this->data = nullptr;
        top = -1;
        capacity = 0;
    }
    
    Stack(const Stack& rhs) {
        copyStack(rhs);
    }

    Stack& operator=(const Stack& rhs) {
        if (this != &rhs) {
            freeMemory();
            copyStack(rhs);
        }
        return *this;
    }

    ~Stack() {
        freeMemory();
    }

    void push(int number) {
        if (top < capacity - 1) {
            top++;
            data[top] = number;
        } else {
            throw std::overflow_error("Stack is full");
        }
    }

    void pop() {
        if (top > -1) {
            top--;
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    int peek() const {
        if (top > -1) {
            return data[top];
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    // s.push(4); // overflow
    cout << s.peek(); // 3
    s.pop();
    cout << s.peek(); // 2
    s.pop();
    cout << s.peek(); // 1
    s.pop();
    // s.pop(); // underflow
    cout << s.isEmpty(); // 1 = true, is indeed empty
}

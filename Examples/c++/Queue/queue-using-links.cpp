#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* previous = nullptr;

    Node(int data, Node* previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};

class Queue {
private:
    Node* front = nullptr;
    Node* back = nullptr;
public:
    Queue() = default;

    void copyQueue(const Queue& rhs) {
        Node* i = rhs.front;
        while (i != nullptr) {
            push(i->data);
            i = i->previous;
        }
    }

    void freeMemory() {
        while(front != nullptr) {
            Node* previous = front->previous;
            delete front;
            front = previous;
        }
    }
    
    Queue(const Queue& rhs) {
        copyQueue(rhs);
    }

    Queue& operator=(const Queue& rhs) {
        if (this != &rhs) {
            freeMemory();
            copyQueue(rhs);
        }
        return *this;
    }

    ~Queue() {
        // freeMemory();
    }

    void push(int number) {
        if (isEmpty()) {
            front = new Node(number);
            back = front;
        } else {
            back->previous = new Node(number);
            back = back->previous;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node* oldFront = front;
            front = front->previous;
            delete oldFront;
        } else {
            throw std::underflow_error("Queue is empty");
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return front->data;
        } else {
            throw std::underflow_error("Queue is empty");
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);

    Queue d(s);
    while (!d.isEmpty()) {
        cout << d.peek();
        d.pop();
    }
}

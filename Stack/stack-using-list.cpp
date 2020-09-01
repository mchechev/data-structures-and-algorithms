#include <iostream>
#include <stdexcept>
#include <list>
using namespace std;

class Stack {
private:
    list<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }

    void pop() {
        data.pop_back();
    }

    int peek() const {
        if (data.size() > 0) {
            return data.back();
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        cout << s.peek();
        s.pop();
    }
}

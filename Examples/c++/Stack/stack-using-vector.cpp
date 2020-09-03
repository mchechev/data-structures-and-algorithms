#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data;
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

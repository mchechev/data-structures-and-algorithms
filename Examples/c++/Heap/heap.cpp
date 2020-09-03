#include <vector>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class Heap {
private:
    vector<int> data;

    int getLeft(int pos) {
        return (pos * 2) + 1;
    }

    int getRight(int pos) {
        return (pos * 2) + 2;
    }

    int getParent(int pos) {
        return (pos - 1) / 2;
    }

    void siftUp(int pos) {
        int parent = getParent(pos);
        while (data[pos] > data[parent]) {
            swap(data[pos], data[parent]);
            if (parent <= 0) {
                return;
            }
            parent = getParent(parent);
            pos = getParent(pos);
        }
    }

    void siftDown(int pos) {
        bool hasRight = getRight(pos) < data.size();
        bool hasLeft = getLeft(pos) < data.size();

        if (hasRight && (data[pos] < data[getLeft(pos)] || data[pos] < data[getRight(pos)])) {
            int swapWith = -1;
            if (data[getLeft(pos)] < data[getRight(pos)]) {
                swapWith = getRight(pos);
            } else {
                swapWith = getLeft(pos);   
            }
            
            swap(data[pos], data[swapWith]);
            siftDown(swapWith);
        }
        else if (hasLeft && data[pos] < data[getLeft(pos)]) {
            swap(data[pos], data[getLeft(pos)]);
            siftDown(getLeft(pos));
        }
    }

public:
    bool isEmpty() const {
        return data.size() == 0;
    }
    void add(int number) {
        data.push_back(number);
        if (data.size() != 0) {
            siftUp(data.size() - 1);
        }
    }

    int peekTop() {
        return data[0];
    }

    void popTop() {
        if (isEmpty()) {
            return;
        }

        swap(data[0], data[data.size() - 1]);
        data.pop_back();
        siftDown(0);
    }
};

int main() {
    Heap s;
    s.add(1);
    s.add(5);
    s.add(3);
    s.add(4);
    s.add(2);

    while(!s.isEmpty()) {
        cout << s.peekTop() << " ";
        s.popTop();
    }
    cout << "\n";
}

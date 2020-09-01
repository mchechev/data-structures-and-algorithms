#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class SinglyLL {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    SinglyLL() = default;
    
    void freeMemory() {
        Node* i = head;
        while(i != nullptr) {
            Node* next = i->next;
            delete i;
            i = next;
        }

        head = nullptr;
        tail = nullptr;
    }

    ~SinglyLL() {
        freeMemory();
    }

    void copyLinkedList(const SinglyLL& rhs) {
        Node* i = rhs.head;
        while(i != nullptr) {
            push_back(i->data);
            i = i->next;
        }
    }

    SinglyLL& operator=(const SinglyLL& rhs) {
        if (this != &rhs) {
            freeMemory();
            copyLinkedList(rhs);
        }
        return *this;
    }

    SinglyLL(const SinglyLL& rhs) {
        copyLinkedList(rhs);
    }

    void push_front(int number) {
        Node* newHead = new Node(number, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        } else {
            tail->next = new Node(number);
            tail = tail->next;
        }
    }

    void print() const {
        Node* i = head;
        while (i != nullptr) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << "\n";
    }

    int peek_front() {
        if (head != nullptr) {
            return head->data;
        } else {
            throw std::out_of_range("List is empty, cannot peek_front()");
        }
    }

    int peek_back() {
        if (tail != nullptr) {
            return tail->data;
        } else {
            throw std::out_of_range("List is empty, cannot peek_back()");
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node* oldHead = head;
            if (tail == head) {
                tail = nullptr;
            }
            head = head->next;
            delete oldHead;
        } else {
            throw std::out_of_range("List is empty, cannot pop_front()");
        }
    }

    void pop_back() {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }

            // Find the node pointing to the tail
            Node* i = head;
            while (i-> next != nullptr && i->next != tail) {
                i = i->next;
            }

            // Delete the tail and point tail to the current node (i)
            delete i->next;
            i->next = nullptr;
            tail = i;
        } else {
            throw std::out_of_range("List is empty, cannot pop_front()");
        }
    }

    void insert(int number, int position) {
        if (position == 0) {
            push_front(number);
            return;
        }

        if (head == nullptr) {
            throw std::out_of_range("Invalid insert index, list is empty");
        }

        Node* current = head;
        Node* previous = nullptr;
        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                previous = current;
                current = current->next;
            } else {
                throw std::out_of_range("Cannot insert in invalid position");
            }
        }

        previous->next = new Node(number, current);
        if (tail == previous) {
            tail = previous->next;
        }
    }

    int get(int position) {
        if (head == nullptr) {
            throw std::out_of_range("List is empty, cannot get from it");
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                current = current->next;
            } else {
                throw std::out_of_range("Cannot get from list, no such position");
            }
        }

        return current->data;
    }

    void remove(int position) {
        if (position == 0) {
            pop_front();
            return;
        }

        if (head == nullptr) {
            throw std::out_of_range("Invalid remove index, list is empty");
        }

        Node* current = head;
        Node* previous = nullptr;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                previous = current;
                current = current->next;
            } else {
                throw std::out_of_range("Cannot insert in invalid position");
            }
        }

        previous->next = current->next;
        if (tail == current) {
            tail = previous;
        }
        delete current;
    }
    
};

int main() {
    SinglyLL l;
    l.insert(0, 0);
    l.insert(1, 1);
    l.insert(2, 2);
    l.insert(3, 3);
    l.print();
}
package basic.data.structures;

import java.util.Comparator;

/**
 * Heap implementation with an array.
 * O(1) top operation.
 * O(log N) push and pop operations.
 *
 * @param <T> Type of the elements of the stack.
 */
public class Heap<T extends Comparable<? super T>> {
    private static final int DEFAULT_CAPACITY = 16;

    private Object[] elements;

    private int capacity;
    private int size;

    private Comparator<T> comparator;

    public Heap(Comparator<T> comparator) {
        this.comparator = comparator;

        this.elements = new Object[DEFAULT_CAPACITY];
        this.size = 0;
        this.capacity = DEFAULT_CAPACITY;
    }

    public void push(T value) {
        checkCapacity(size + 1);
        elements[size++] = value;
        pushUp(size - 1);
    }

    void pop() {
        if (size == 0) {
            return;
        }

        checkCapacity(size - 1);

        size--;
        Object temp = elements[0];
        elements[0] = elements[size];
        elements[size] = temp;
        heapify(0);
    }

    @SuppressWarnings("unchecked")
    public T top() {
        return (T) elements[0];
    }

    public T poll() {
        T returnValue = top();
        pop();
        return returnValue;
    }

    public int size() {
        return size;
    }

    public boolean empty() {
        return size == 0;
    }

    @SuppressWarnings("unchecked")
    private void pushUp(int node) {
        int parent = (node - 1) / 2;
        while (node != 0 && comparator.compare((T) elements[node], (T) elements[parent]) < 0) {
            Object temp = elements[node];
            elements[node] = elements[parent];
            elements[parent] = temp;

            node = parent;
            parent = (node - 1) / 2;
        }
    }

    @SuppressWarnings("unchecked")
    private void heapify(int node) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        int nextNode = node;

        if (left < size && comparator.compare((T) elements[left], (T) elements[nextNode]) < 0) {
            nextNode = left;
        }

        if (right < size && comparator.compare((T) elements[right], (T) elements[nextNode]) < 0) {
            nextNode = right;
        }

        if (nextNode != node) {
            Object temp = elements[node];
            elements[node] = elements[nextNode];
            elements[nextNode] = temp;

            heapify(nextNode);
        }
    }

    private void checkCapacity(int newSize) {
        if (newSize >= 2 * capacity / 3) {
            resize(capacity * 2);
        }

        if (newSize <= capacity / 3 && capacity > DEFAULT_CAPACITY)  {
            resize(capacity / 2);
        }
    }

    private void resize(int newCapacity) {
        Object[] temp = new Object[size];

        System.arraycopy(elements, 0, temp, 0, size);

        capacity = newCapacity;
        elements = new Object[capacity];

        System.arraycopy(temp, 0, elements, 0, size);
    }
}

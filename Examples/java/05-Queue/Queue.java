package basic.data.structures;

/**
 *  * Queue implementation with an array.
 *  * O(1) push, pop and front operations (Constant Amortized Time)
 *
 * @param <T> Type of the elements of the stack.
 */
public class Queue<T> {
    private static final int DEFAULT_CAPACITY = 16;

    private Object[] elements;
    private int capacity;
    private int left;
    private int right;

    /**
     * Create an empty queue.
     */
    public Queue() {
        elements = new Object[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
        left = 0;
        right = -1;
    }

    /**
     * Add an element to the back of the queue.
     *
     * @param value Object to be added.
     */
    public void push(T value) {
        checkCapacity(right - left + 2);

        if (right + 1 == capacity) {
            shift();
        }

        elements[++right] = value;
    }

    /**
     * Return the element at the front of the queue.
     *
     * @return Reference to the object.
     */
    @SuppressWarnings("unchecked")
    public T front() {
        if (left > right) {
            throw new IllegalStateException("Queue is empty");
        }

        return (T) elements[left];
    }

    /**
     * Remove an element from the front of the queue.
     */
    public void pop() {
        if (left > right) {
            throw new IllegalStateException("Queue is empty");
        }

        checkCapacity(right - left);
        left++;
    }

    /**
     * Remove the front element from the queue.
     *
     * @return Reference to the removed object.
     */
    public T poll() {
        T result = front();
        pop();
        return  result;
    }

    public int size() {
        return right - left + 1;
    }

    public boolean empty() {
        return size() == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("[");

        for (int i = left; i <= right; i++) {
            sb.append(elements[i].toString()).append(", ");
        }

        if (left <= right) {
            sb.delete(sb.length() - 2, sb.length());
        }

        sb.append("]");

        return sb.toString();
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
        Object[] temp = new Object[right - left + 1];

        System.arraycopy(elements, left, temp, left, right - left + 1);

        capacity = newCapacity;
        elements = new Object[capacity];

        System.arraycopy(temp, 0, elements, 0, right - left + 1);
    }

    private void shift() {
        for (int i = 0; i < right - left + 1; i++) {
            elements[i] = elements[left + 1];
        }

        right = right - left;
        left = 0;
    }
}

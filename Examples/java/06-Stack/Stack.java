package basic.data.structures;

/**
 * Stack implementation with an array.
 * O(1) push, pop and top operations (Constant Amortized Time)
 *
 * @param <T> Type of the elements of the stack.
 */
public class Stack<T> {
    private static final int DEFAULT_CAPACITY = 16;

    private Object[] elements;
    private int capacity;
    private int size;

    /**
     * Create an empty stack.
     */
    public Stack() {
        elements = new Object[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
        size = 0;
    }

    /**
     * Add an element to the top of the stack.
     *
     * @param value Object to be added.
     */
    public void push(T value) {
        checkCapacity(size + 1);
        elements[size++] = value;
    }

    /**
     * Return the element at the top of the stack.
     *
     * @return Reference to the object.
     */
    @SuppressWarnings("unchecked")
    public T top() {
        if (size == 0) {
            throw new IllegalStateException("Stack is empty");
        }

        return (T) elements[size - 1];
    }

    /**
     * Remove an element from the top of the stack.
     */
    public void pop() {
        if (size == 0) {
            throw new IllegalStateException("Stack is empty");
        }

        size--;
    }

    /**
     * Remove the top element from the stack.
     *
     * @return Reference to the removed object.
     */
    public T poll() {
        T result = top();
        pop();
        return result;
    }

    /**
     * @return The current number of elements in the stack.
     */
    public int size() {
        return size;
    }

    /**
     * @return True if the stack has no elements and false otherwise.
     */
    public boolean empty() {
        return size == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("[");

        for (int i = 0; i < size; i++) {
            sb.append(elements[i].toString()).append(", ");
        }

        if (size > 0) {
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
        Object[] temp = new Object[size];

        System.arraycopy(elements, 0, temp, 0, size);

        capacity = newCapacity;
        elements = new Object[capacity];

        System.arraycopy(temp, 0, elements, 0, size);
    }
}

package basic.data.structures;

/**
 * Stack implementation with an array.
 * O(1) push, pop and top operations (Constant Amortized Time)
 * O(1) minimum retrieval with O(size) extra space
 *
 * @param <T> Type of the elements of the stack.
 */
public class MinStack<T extends Comparable<? super T>> extends Stack<T> {
    private final Stack<T> minStack;

    /**
     * Create an empty stack.
     */
    public MinStack() {
        super();
        minStack = new Stack<>();
    }

    /**
     * Add an element to the top of the stack.
     *
     * @param value Object to be added.
     */
    @Override
    public void push(T value) {
        super.push(value);

        if (minStack.size() == 0 || value.compareTo(minStack.top()) < 0) {
            minStack.push(value);
        }
    }

    /**
     * Remove an element from the top of the stack.
     */
    @Override
    public void pop() {
        if (minStack.size() == 0) {
            throw new IllegalStateException("Stack is empty");
        }

        if (minStack.top().compareTo(super.top()) == 0) {
            minStack.pop();
        }

        super.pop();
    }

    /**
     * Remove the top element from the stack.
     *
     * @return Reference to the removed object.
     */
    @Override
    public T poll() {
        T result = super.top();
        pop();
        return result;
    }

    /**
     * Return the minimum element in the stack.
     *
     * @return Reference to the object.
     */
    public T minimum() {
        if (minStack.size() == 0) {
            throw new IllegalStateException("Stack is empty");
        }

        return minStack.top();
    }
}

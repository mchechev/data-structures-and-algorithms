package basic.data.structures;

/**
 * Queue implementation with an array.
 * O(1) push, pop and front operations (Constant Amortized Time)
 * O(1) minimum element retrieval with O(size) extra space
 *
 * @param <T> Type of the elements of the stack.
 */
public class MinQueue<T extends Comparable<? super T>> extends Queue<T> {
    private final DoublyLinkedList<T> minList;

    /**
     * Create an empty queue.
     */
    public MinQueue() {
        super();
        minList = new DoublyLinkedList<>();
    }

    /**
     * Add an element to the back of the queue.
     *
     * @param value Object to be added.
     */
    @Override
    public void push(T value) {
        while (minList.size() > 0 && minList.getEnd().compareTo(value) > 0) {
            minList.eraseEnd();
        }
        minList.addToEnd(value);

        super.push(value);
    }

    /**
     * Remove an element from the front of the queue.
     */
    @Override
    public void pop() {
        if (minList.size() == 0) {
            throw new IllegalStateException("Queue is empty");
        }

        if (minList.getBeginning().compareTo(super.front()) == 0) {
            minList.eraseBeginning();
        }

        super.pop();
    }

    /**
     * Remove the front element from the queue.
     *
     * @return Reference to the removed object.
     */
    @Override
    public T poll() {
        T result = super.front();
        pop();
        return result;
    }

    /**
     * Return the minimum element in the queue.
     *
     * @return Reference to the object.
     */
    public T minimum() {
        if (minList.size() == 0) {
            throw new IllegalStateException("Queue is empty");
        }

        return minList.getBeginning();
    }
}

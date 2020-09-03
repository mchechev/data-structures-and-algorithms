package basic.data.structures;

import java.util.Iterator;

/**
 * Doubly Linked List.
 * Each element has a link to the next element and the previous element.
 *
 * O(1) access, insertion and deletion at the beginning of the list.
 * O(1) access, insertion and deletion at the ending of the list.
 * O(size) access, insertion and deletion in the middle of the list.
 *
 * @param <T> Type of the objects stored in the Linked List
 */
public class DoublyLinkedList<T> implements Iterable<T> {
    private class Node {
        T value;
        Node next;
        Node previous;

        Node () {
            value = null;
            next = null;
            previous = null;
        }

        Node (T v, Node n, Node p) {
            value = v;
            next = n;
            previous = p;
        }
    }

    private Node first;
    private Node last;

    private int size;

    /**
     * Create an empty doubly linked list.
     */
    public DoublyLinkedList() {
        first = null;
        last = null;
        size = 0;
    }

    /**
     * Insert the object at the end of the doubly linked list.
     *
     * @param value The object ot be inserted.
     */
    public void addToEnd(T value) {
        size++;

        if (last == null) {
            first = new Node(value, null, null);
            last = first;
            return;
        }

        last.next = new Node(value, null, last);
        last = last.next;
    }

    /**
     * Insert the object at the start of the doubly linked list.
     *
     * @param value The object ot be inserted.
     */
    public void addToBeginning(T value) {
        size++;

        if (first == null) {
            first = new Node(value, null, null);
            last = first;
            return;
        }

        first = new Node(value, first, null);
    }

    /**
     * Insert the object at a given position in the doubly linked list.
     *
     * @param value The object ot be inserted.
     * @param position The position of the insertion.
     */
    public void insertAt(T value, int position) {
        if (position < 0) {
            throw new IllegalArgumentException("Can't add element at negative position");
        }

        if (position >= size) {
            addToEnd(value);
            return;
        }

        if (position == 0) {
            addToBeginning(value);
            return;
        }

        size++;

        Node temp = goToPosition(position - 1);
        temp.next = new Node(value, temp.next, temp);
        temp.next.next.previous = temp.next;
    }

    /**
     * Erase the first element of the doubly linked list.
     */
    public void eraseBeginning() {
        if (size == 0) {
            throw new IllegalStateException("Can't delete form an empty LinkedList");
        }

        size--;
        first = first.next;

        if (first != null) {
            first.previous = null;
        }
    }

    /**
     * Erase the last element of the doubly linked list.
     */
    public void eraseEnd() {
        if (size == 0) {
            throw new IllegalStateException("Can't delete form an empty LinkedList");
        }

        size--;

        last = last.previous;

        if (last != null) {
            last.next = null;
        }
    }

    /**
     * Erase the element at a given position in the doubly linked list.
     *
     * @param position The position of the object.
     */
    public void eraseAt(int position) {
        if (position < 0 || position >= size) {
            throw new IllegalArgumentException("Position is out of bounds");
        }

        if (position == 0) {
            eraseBeginning();
            return;
        }

        if (position == size - 1) {
            eraseEnd();
            return;
        }

        size--;

        Node temp = goToPosition(position - 1);
        temp.next = temp.next.next;
        temp.next.previous = temp;
    }

    /**
     * Return the last element of the doubly linked list.
     *
     * @return Reference to the object.
     */
    public T getBeginning() {
        if (size == 0) {
            return  null;
        }

        return first.value;
    }

    /**
     * Return the first element of the doubly linked list.
     *
     * @return Reference to the object.
     */
    public T getEnd() {
        if (size == 0) {
            return  null;
        }

        return last.value;
    }

    /**
     * Return the element at a given position in the doubly linked list.
     *
     * @param position The position of the object.
     * @return Reference to the object.
     */
    public T get(int position) {
        if (position < 0 || position >= size) {
            throw new IllegalArgumentException("Position is out of bounds");
        }

        return goToPosition(position).value;
    }

    /**
     * Reverse the elements of the linked list.
     * O(size) complexity.
     */
    public void reverse() {
        Node forward = first;
        Node backward = last;

        int cnt = 0;
        while (cnt < size / 2) {
            T temp = forward.value;
            forward.value = backward.value;
            backward.value = temp;

            forward = forward.next;
            backward = backward.previous;
            cnt++;
        }
    }

    /**
     * @return Current number of elements in the linked list.
     */
    public int size() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("[");

        this.forEach(value -> sb.append(value.toString()).append(", "));

        if (size > 0) {
            sb.delete(sb.length() - 2, sb.length());
        }

        sb.append("]");

        return sb.toString();
    }

    @Override
    public Iterator<T> iterator() {
        return new LinkedListIterator();
    }

    private Node goToPosition(int position) {
        if (position < size - position) {
            int index = 0;
            Node temp = first;

            while (index < position) {
                index++;
                temp = temp.next;
            }

            return temp;
        }

        int index = size - 1;
        Node temp = last;

        while (index > position) {
            index--;
            temp = temp.previous;
        }

        return temp;
    }

    private class LinkedListIterator implements Iterator<T> {

        private int index = 0;
        private Node current = first;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public T next() {
            T value = current.value;

            index++;
            current = current.next;

            return value;
        }

        @Override
        public void remove() {
            eraseAt(index);
        }
    }
}

package basic.data.structures;

import java.util.Iterator;

/**
 * Singly Linked List.
 * Each element has a link to the next element.
 *
 * O(1) access, insertion and deletion at the beginning of the list.
 * O(1) access and insertion at the ending of the list.
 * O(size) deletion at the ending of the list.
 * O(size) access, insertion and deletion in the middle of the list.
 *
 * @param <T> Type of the objects stored in the Linked List
 */
public class LinkedList<T> implements Iterable<T> {
    private class Node {
        T value;
        Node link;

        Node () {
            value = null;
            link = null;
        }

        Node (T v, Node l) {
            value = v;
            link = l;
        }
    }

    private Node first;
    private Node last;

    private int size;

    /**
     * Create an empty linked list
     */
    public LinkedList() {
        first = null;
        last = null;
        size = 0;
    }

    /**
     * Insert the object at the end of the linked list.
     *
     * @param value The object ot be inserted.
     */
    public void addToEnd(T value) {
        size++;

        if (last == null) {
            first = new Node(value, null);
            last = first;
            return;
        }

        last.link = new Node(value, null);;
        last = last.link;
    }

    /**
     * Insert the object at the start of the linked list.
     *
     * @param value The object ot be inserted.
     */
    public void addToBeginning(T value) {
        size++;

        if (first == null) {
            first = new Node(value, null);
            last = first;
            return;
        }

        first = new Node(value, first);
    }

    /**
     * Insert the object at a given position in the linked list.
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
        temp.link = new Node(value, temp.link);
    }

    /**
     * Erase the first element of the linked list.
     */
    public void eraseBeginning() {
        if (size == 0) {
            throw new IllegalStateException("Can't delete form an empty LinkedList");
        }

        size--;
        first = first.link;
    }

    /**
     * Erase the last element of the linked list.
     */
    public void eraseEnd() {
        if (size == 0) {
            throw new IllegalStateException("Can't delete form an empty LinkedList");
        }

        size--;

        Node temp = goToPosition(size - 1);

        temp.link = null;
        last = temp;
    }

    /**
     * Erase the element at a given position in the linked list.
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
        temp.link = temp.link.link;
    }

    /**
     * Return the last element of the linked list.
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
     * Return the first element of the linked list.
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
     * Return the element at a given position in the linked list.
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
        if (size == 2) {
            T temp = first.value;
            first.value = last.value;
            last.value = temp;
            return;
        }

        Node prev = first;
        Node cur = prev.link;
        Node next = cur.link;

        while (next != null) {
            cur.link = prev;

            prev = cur;
            cur = next;
            next = next.link;
        }

        cur.link = prev;
        first.link = null;

        Node temp = first;
        first = last;
        last = temp;
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
        int index = 0;
        Node temp = first;

        while (index < position) {
            index++;
            temp = temp.link;
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
            current = current.link;

            return value;
        }

        @Override
        public void remove() {
            eraseAt(index);
        }
    }
}

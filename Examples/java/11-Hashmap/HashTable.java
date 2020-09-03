package basic.data.structures;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.function.BiConsumer;

/**
 * Hash table implementation with the bucket mechanism for conflict resolution.
 *
 * O(1) put, get, remove operations (Constant Amortized Time)
 *
 * @param <K> Type of the keys
 * @param <V> Type of the values
 */
public class HashTable<K, V> {
    private static final int DEFAULT_SIZE = 16;

    static class Node<K, V> {
        K key;
        V value;

        Node<K, V> next;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    private List<Node<K, V>> buckets;

    private int numberOfBuckets;
    private int emptyBuckets;

    private int size;

    /**
     * Create an empty hash table.
     */
    public HashTable() {
        buckets = new ArrayList<>();
        numberOfBuckets = DEFAULT_SIZE;
        emptyBuckets = DEFAULT_SIZE;
        size = 0;

        for (int i = 0; i < DEFAULT_SIZE; i++)
            buckets.add(null);
    }

    /**
     * Add a (key, value) to the hash table.
     * @param key Object representing the key.
     * @param value Object representing the value.
     */
    public void put(K key, V value) {
        if (get(key) != null) {
            return;
        }

        size++;

        int bucketIndex = getBucketIndex(key);
        Node<K, V> current = buckets.get(bucketIndex);
        Node<K, V> newNode = new Node<>(key, value);

        if (buckets.get(bucketIndex) == null) {
            emptyBuckets--;
        }

        newNode.next = current;
        buckets.set(bucketIndex, newNode);

        if (size >= 2 * numberOfBuckets / 3) {
            resize(2 * numberOfBuckets);
        }
    }

    /**
     * Returns the value corresponding to the (key, value) pair with the given key.
     *
     * @param key Key corresponding to the needed value.
     * @return Object reference to the value corresponding to the given key.
     */
    public V get(K key) {
        int bucketIndex = getBucketIndex(key);
        Node<K, V> current = buckets.get(bucketIndex);

        while (current != null) {
            if (current.key.equals(key)) {
                return current.value;
            }
            current = current.next;
        }

        return null;
    }

    /**
     * Erase the (key, value) pair with the given key.
     *
     * @param key Key corresponding to the value that needs to be erased.
     */
    public void erase(K key) {
        int bucketIndex = getBucketIndex(key);

        Node<K, V> current = buckets.get(bucketIndex);
        Node<K, V> previous = null;

        while (current != null && !current.key.equals(key)) {
            previous = current;
            current = current.next;
        }

        if (current == null) {
            return;
        }

        size--;

        if (previous != null) {
            previous.next = current.next;
            return;
        }

        buckets.set(bucketIndex, current.next);

        if (buckets.get(bucketIndex) == null) {
            emptyBuckets++;
        }

        if (emptyBuckets >= 2 * numberOfBuckets / 3 && numberOfBuckets > DEFAULT_SIZE) {
            resize(numberOfBuckets / 2);
        }
    }

    /**
     * @return Current number of (key, value) pairs in the hash table.
     */
    public int size() {
        return size;
    }

    /**
     * @return True if the hash table has no elements and false otherwise.
     */
    public boolean empty() {
        return size == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");

        this.forEach((key, value) -> {
            sb.append("(").append(key.toString()).append(", ").append(value.toString()).append("), ");
        });

        if (sb.length() > 1) {
            sb.delete(sb.length() - 2, sb.length());
        }

        sb.append("}");
        return sb.toString();
    }

    public void forEach(BiConsumer<? super K, ? super V> consumer) {
        Objects.requireNonNull(consumer);

        buckets.forEach(node -> {
            while (node != null) {
                consumer.accept(node.key, node.value);
                node = node.next;
            }
        });
    }

    private void resize(int newSize) {
        List<Node<K, V>> temp = buckets;

        buckets = new ArrayList<>();
        numberOfBuckets = newSize;
        size = 0;

        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(null);
        }

        for (Node<K, V> node : temp) {
            while (node != null) {
                put(node.key, node.value);
                node = node.next;
            }
        }
    }

    private int getBucketIndex(K key) {
        int hashCode = key.hashCode();
        return hashCode % numberOfBuckets;
    }
}
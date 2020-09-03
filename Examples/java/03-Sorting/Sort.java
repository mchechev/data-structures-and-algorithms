package Sorting;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

/**
 * Contains implementation of the following sorting algorithms:
 * <ul>
 *     <li>selection sort</li>
 *     <li>bubble sort</li>
 *     <li>insertion sort</li>
 *     <li>quick sort</li>
 *     <li>merge sort</li>
 *     <li>heap sort</li>
 *     <li>counting sort</li>
 *     <li>radix sort</li>
 * </ul>
 */
public class Sort {
    private static final Random rng = new Random();

    /**
     * Sorts an interval from a list of objects in ascending order with selection sort.
     *
     * @param list List of object to be sorted.
     * @param from Start of the interval.
     * @param to End of the interval.
     */
    public static <T extends Comparable<? super T>> void selectionSort(List<T> list, int from, int to) {
        for (int i = from; i <= to; i++) {
            int selected = i;

            for (int j = i + 1; j <= to; j++) {
                if (list.get(selected).compareTo(list.get(j)) > 0) {
                    selected = j;
                }
            }

            swap(list, i, selected);
        }
    }

    /**
     * Sorts a list of objects in ascending order with selection sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void selectionSort(List<T> list) {
        selectionSort(list, 0, list.size() - 1);
    }

    /**
     * Sorts an interval from a list of objects in ascending order with bubble sort.
     *
     * @param list List of object to be sorted.
     * @param from Start of the interval.
     * @param to End of the interval.
     */
    public static <T extends Comparable<? super T>> void bubbleSort(List<T> list, int from, int to) {
        for (int i = from; i <= to; i++) {
            for (int j = i; j > from && list.get(j).compareTo(list.get(j - 1)) < 0; j--) {
                swap(list, j, j - 1);
            }
        }
    }

    /**
     * Sorts a list of objects in ascending order with bubble sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void bubbleSort(List<T> list) {
        bubbleSort(list, 0, list.size() - 1);
    }

    /**
     * Sorts an interval from a list of objects in ascending order with insertion sort.
     *
     * @param list List of object to be sorted.
     * @param from Start of the interval.
     * @param to End of the interval.
     */
    public static <T extends Comparable<? super T>> void insertionSort(List<T> list, int from, int to) {
        for (int i = from + 1; i <= to; i++) {
            T value = list.get(i);

            int j = i - 1;

            while (j >= 0 && list.get(j).compareTo(value) > 0) {
                list.set(j + 1, list.get(j));
                j--;
            }

            list.set(j + 1, value);
        }
    }

    /**
     * Sorts a list of objects in ascending order with insertion sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void insertionSort(List<T> list) {
        insertionSort(list, 0, list.size() - 1);
    }


    /** Sorts an interval from a list of objects in ascending order with quick sort.
     *
     * @param list List of object to be sorted.
     * @param from Start of the interval.
     * @param to End of the interval.
     */
    public static <T extends Comparable<? super T>> void quickSort(List<T> list, int from, int to) {
        if (to - from <= 0) {
            return;
        }

        int pivot = partition(list, from, to);

        quickSort(list, from, pivot - 1);
        quickSort(list, pivot + 1, to);
    }

    /**
     * Sorts a list of objects in ascending order with quick sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void quickSort(List<T> list) {
        quickSort(list, 0, list.size() - 1);
    }

    /** Sorts an interval from a list of objects in ascending order with merge sort.
     *
     * @param list List of object to be sorted.
     * @param from Start of the interval.
     * @param to End of the interval.
     */
    public static <T extends Comparable<? super T>> void mergeSort(List<T> list, int from, int to) {
        if (to - from <= 0) {
            return;
        }

        int mid = (from + to) / 2;

        mergeSort(list, from, mid);
        mergeSort(list, mid + 1, to);

        merge(list, from, mid, to);
    }

    /**
     * Sorts a list of objects in ascending order with merge sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void mergeSort(List<T> list) {
        mergeSort(list, 0, list.size() - 1);
    }

    /**
     * Sorts a list of objects in ascending order with heap sort.
     *
     * @param list List of object to be sorted.
     */
    public static <T extends Comparable<? super T>> void heapSort(List<T> list) {
        for (int i = list.size() / 2 - 1; i >= 0; i--) {
            hepify(list, list.size(), i);
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            swap(list, i, 0);
            hepify(list, i, 0);
        }
    }

    /**
     * Sorts a list of numbers in ascending order with counting sort.
     *
     * @param list List of numbers to be sorted.
     */
    public static void countingSort(List<Integer> list) {
        int maxElement = Integer.MIN_VALUE;
        int minElement = Integer.MAX_VALUE;

        for (int num : list) {
            maxElement = Math.max(maxElement, num);
            minElement = Math.min(minElement, num);
        }

        final int OFFSET = Math.max(0, -minElement);

        HashMap<Integer, Integer> count = new HashMap<>();

        for (int num : list) {
            count.put(num + OFFSET, count.getOrDefault(num + OFFSET, 1));
        }

        list.clear();

        count.forEach((key, value) -> {
            for (int i = 0; i < value; i++) {
                list.add(key - OFFSET);
            }
        });
    }

    /**
     * Sorts a list of numbers in ascending order with radix sort.
     *
     * @param list List of numbers to be sorted.
     */
    public static void radixSort(List<Integer> list) {
        int maxElement = Integer.MIN_VALUE;

        for (int num : list) {
            maxElement = Math.max(maxElement, num);
        }

        for (int pos = 1; maxElement / pos > 0; pos *= 10) {
            int[] count = new int[10];

            for (int num : list) {
                count[(num / pos) % 10]++;
            }

            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }

            ArrayList<Integer> res = new ArrayList<>(list);

            for (int i = list.size() - 1; i >= 0; i--) {
                int digit = (list.get(i) / pos) % 10;

                res.set(count[digit] - 1, list.get(i));

                count[digit]--;
            }

            list.clear();
            list.addAll(res);
        }
    }

    // Helper method for heap sort
    public static <T extends Comparable<? super T>> void hepify(List<T> list, int n, int node)  {
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        int root = node;

        if (left < n && list.get(left).compareTo(list.get(root)) > 0) {
            root = left;
        }

        if (right < n && list.get(right).compareTo(list.get(root)) > 0) {
            root = right;
        }

        if (root != node) {
            swap(list, node, root);
            hepify(list, n, root);
        }
    }

    // Helper method from merge sort
    private static <T extends Comparable<? super T>> void merge(List<T> list, int from, int mid, int to) {
        List<T> left = new ArrayList<>();
        List<T> right = new ArrayList<>();

        for (int i = from; i <= mid; i++) {
            left.add(list.get(i));
        }

        for (int i = mid + 1; i <= to; i++) {
            right.add(list.get(i));
        }

        int i = 0;
        int j = 0;

        int index = from;
        while (i < left.size() && j < right.size()) {
            if (left.get(i).compareTo(right.get(j)) < 0) {
                list.set(index, left.get(i));
                i++;
            } else {
                list.set(index, right.get(j));
                j++;
            }
            index++;
        }

        while (i < left.size()) {
            list.set(index, left.get(i));
            i++;
            index++;
        }

        while (j < right.size()) {
            list.set(index, right.get(j));
            j++;
            index++;
        }
    }

    // Helper method for for quick sort
    private static <T extends Comparable<? super T>> int partition(List<T> list, int left, int right) {
        int pivot = left + rng.nextInt(right - left + 1);
        swap(list, pivot, right);

        int i = left;
        for (int j = left; j < right; j++) {
            if (list.get(j).compareTo(list.get(right)) <= 0) {
                swap(list, i, j);
                i++;
            }
        }

        swap(list, i, right);
        return i;
    }

    private static <T> void swap(List<T> list, int i, int j) {
        T temp = list.get(j);
        list.set(j, list.get(i));
        list.set(i, temp);
    }
}

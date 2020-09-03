package search;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Contains implementation of the following searches:
 * <ul>
 *     <li>binary search</li>
 *     <li>jump search</li>
 *     <li>exponential search</li>
 *     <li>ternary search</li>
 *     <li>quick select</li>
 * </ul>
 */
public class Search {
    private static final Random rng = new Random();

    /**
     * Search for an object in an interval from a list of sorted objects with binary search.
     * O(log2(right - left + 1))
     *
     * @param list sorted sequence of comparable objects
     * @param obj object to search for
     * @param left Start of the interval.
     * @param right End of the interval.
     * @return true if obj is in the list and false otherwise
     */
    public static <T extends Comparable<? super T>> boolean binarySearch(final List<T> list, final T obj, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;

            if (list.get(mid).equals(obj)) {
                return true;
            }

            if (list.get(mid).compareTo(obj) < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    /**
     * Search for an object in a list of sorted objects with binary search.
     * O(log2(list.size()))
     *
     * @param list sorted sequence of comparable objects
     * @param obj object to search for
     * @return true if obj is in the list and false otherwise
     */
    public static <T extends Comparable<? super T>> boolean binarySearch(final List<T> list, final T obj) {
        int left = 0;
        int right = list.size() - 1;

        return binarySearch(list, obj, left, right);
    }

    /**
     * Search for an object in a list of sorted objects with jump search.
     * O(sqrt(list.size()))
     *
     * @param list Sorted sequence of comparable objects.
     * @param obj Object to search for.
     * @return True if obj is in the list and false otherwise.
     */
    public static <T extends Comparable<? super T>> boolean jumpSearch(final List<T> list, final T obj) {
        int jump = (int) Math.round(Math.sqrt(list.size()));

        int i = 0;
        while (i < list.size()) {
            if (list.get(i).equals(obj)) {
                return true;
            }

            if (list.get(i).compareTo(obj) > 0) {
                break;
            }

            i = Math.min(i + jump, list.size());
        }

        for (int j = 1; j < jump; j++) {
            if (list.get(i - j).equals(obj)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Search for an object in a list of sorted objects with exponential search.
     * O(log2(list.size()))
     *
     * @param list Sorted sequence of comparable objects.
     * @param obj Object to search for.
     * @return True if obj is in the list and false otherwise.
     */
    public static <T extends Comparable<? super T>> boolean exponentialSearch(final List<T> list, final T obj) {
        if (list.get(0).equals(obj)) {
            return true;
        }

        int exp = 1;
        while (exp < list.size() && list.get(exp).compareTo(obj) < 0) {
            exp *= 2;
        }

        return binarySearch(list, obj, exp / 2, Math.min(exp, list.size() - 1));
    }

    /**
     * Search for an object in an interval from a list of sorted objects with ternary search.
     * O(log2(list.size()))
     *
     * @param list Sorted sequence of comparable objects.
     * @param obj Object to search for.
     * @param left Start of the interval.
     * @param right End of the interval.
     * @return True if obj is in the list and false otherwise.
     */
    public static <T extends Comparable<? super T>> boolean ternarySearch(final List<T> list,
                                                                          final T obj, int left, int right) {
        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (list.get(mid1).equals(obj) || list.get(mid2).equals(obj)) {
                return true;
            }

            if (list.get(mid1).compareTo(obj) > 0) {
                right = mid1 - 1;
            } else if (list.get(mid2).compareTo(obj) < 0){
                left = mid2 + 1;
            } else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }

        return false;
    }

    /**
     * Search for an object in a list of sorted objects with ternary search.
     * O(log2(list.size()))
     *
     * @param list Sorted sequence of comparable objects.
     * @param obj Object to search for.
     * @return True if obj is in the list and false otherwise.
     */
    public static <T extends Comparable<? super T>> boolean ternarySearch(final List<T> list, final T obj) {
        int left = 0;
        int right = list.size() - 1;

        return ternarySearch(list, obj, left, right);
    }

    /**
     * Find the kth smallest element in an interval form a list of comparable objects.
     *
     * @param list Sequence of comparable objects.
     * @param left Start of the interval.
     * @param right End of the interval.
     * @return Kth smallest element in the list.
     */
    public static <T extends Comparable<? super T>> T kthSmallestElement(final List<T> list,
                                                                         int k, int left, int right) {
        List<T> tempList = new ArrayList<>(list);

        while (left <= right) {
            int pivot = partition(tempList, left, right);

            if (pivot == k - 1) {
                return tempList.get(pivot);
            }

            if (pivot < k - 1) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        return null;
    }

    /**
     * Find the kth smallest element in a list of comparable objects.
     *
     * @param list Sequence of comparable objects.
     * @return Kth smallest element in the list.
     */
    public static <T extends Comparable<? super T>> T kthSmallestElement(final List<T> list, int k) {
        int left = 0;
        int right = list.size() - 1;
        return kthSmallestElement(list, k, left, right);
    }

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

package Sorting;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SortTest {
    private static final List<Integer> testList = Arrays.asList(5, 1, 4, 7, 13, 2);
    private static final List<Integer> sortedList = Arrays.asList(1, 2, 4, 5, 7, 13);

    @Test
    public void testSelectionSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.selectionSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testBubbleSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.bubbleSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testInsertionSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.insertionSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testQuickSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.quickSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testMergeSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.mergeSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testHeapSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.heapSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testCountingSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.countingSort(list);
        Assert.assertEquals(sortedList, list);
    }

    @Test
    public void testRadixSort() {
        List<Integer> list = new ArrayList<>(testList);
        Sort.radixSort(list);
        Assert.assertEquals(sortedList, list);
    }
}

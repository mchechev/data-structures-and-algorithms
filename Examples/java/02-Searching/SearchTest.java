package search;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SearchTest {
    private static final List<Integer> testList = Arrays.asList(1, 5, 9, 17, 33, 75);

    @Test
    public void testBinarySearchPositive() {
        Assert.assertTrue(Search.binarySearch(testList, 17));
    }

    @Test
    public void testBinarySearchNegative() {
        Assert.assertFalse(Search.binarySearch(testList, 16));
    }

    @Test
    public void testJumpSearchPositive() {
        Assert.assertTrue(Search.jumpSearch(testList, 17));
    }

    @Test
    public void testJumpSearchNegative() {
        Assert.assertFalse(Search.jumpSearch(testList, 16));
    }

    @Test
    public void testExponentialSearchPositive() {
        Assert.assertTrue(Search.exponentialSearch(testList, 17));
    }

    @Test
    public void testExponentialSearchNegative() {
        Assert.assertFalse(Search.exponentialSearch(testList, 16));
    }

    @Test
    public void testTernarySearchPositive() {
        Assert.assertTrue(Search.ternarySearch(testList, 17));
    }

    @Test
    public void testTernarySearchNegative() {
        Assert.assertFalse(Search.ternarySearch(testList, 16));
    }

    @Test
    public void testKthSmallestPositive() {
        List<Integer> shuffledList = new ArrayList<>(testList);
        Collections.shuffle(shuffledList);
        Assert.assertEquals(9, (int) Search.kthSmallestElement(shuffledList, 3));
    }

    @Test
    public void testTKthSmallestPNegative() {
        List<Integer> shuffledList = new ArrayList<>(testList);
        Collections.shuffle(shuffledList);
        Assert.assertNull(Search.kthSmallestElement(shuffledList, 16));
    }
}

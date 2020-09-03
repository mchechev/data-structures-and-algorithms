package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class HeapTest {
    @Test
    public void testMinHeap() {
        Heap<Integer> heap = new Heap<>(Integer::compare);
        heap.push(7);
        heap.push(5);

        Assert.assertEquals(new Integer(5), heap.top());

        heap.push(6);
        heap.push(3);

        Assert.assertEquals(new Integer(3), heap.poll());
        Assert.assertEquals(new Integer(5), heap.poll());
        Assert.assertEquals(new Integer(6), heap.poll());
        Assert.assertEquals(new Integer(7), heap.poll());
    }

    @Test
    public void testMaxHeap() {
        Heap<Integer> heap = new Heap<>((integer, t1) -> Integer.compare(t1, integer));
        heap.push(7);
        heap.push(5);

        Assert.assertEquals(new Integer(7), heap.top());

        heap.push(9);
        heap.push(3);

        Assert.assertEquals(new Integer(9), heap.poll());
        Assert.assertEquals(new Integer(7), heap.poll());
        Assert.assertEquals(new Integer(5), heap.poll());
        Assert.assertEquals(new Integer(3), heap.poll());
    }
}

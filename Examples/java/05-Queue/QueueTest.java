package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class QueueTest {
    @Test
    public void testQueue() {
        Queue<Integer> queue = new Queue<>();

        queue.push(1);
        queue.push(7);
        queue.push(73);
        queue.push(2);

        Assert.assertEquals(1, (int) queue.poll());
        Assert.assertEquals(7, (int) queue.front());
        Assert.assertEquals("[7, 73, 2]", queue.toString());
    }

    @Test
    public void testMinQueue() {
        MinQueue<Integer> queue = new MinQueue<>();

        queue.push(9);
        Assert.assertEquals(9, (int) queue.minimum());

        queue.push(7);
        Assert.assertEquals(7, (int) queue.minimum());

        queue.push(2);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.push(73);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.push(5);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.pop();
        queue.pop();
        queue.pop();
        Assert.assertEquals(5, (int) queue.minimum());
    }
}

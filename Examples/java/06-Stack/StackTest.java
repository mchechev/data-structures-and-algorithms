package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class StackTest {
    @Test
    public void testStack() {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(7);
        stack.push(73);
        stack.push(2);

        Assert.assertEquals(2, (int) stack.poll());
        Assert.assertEquals(73, (int) stack.top());
        Assert.assertEquals("[1, 7, 73]", stack.toString());
    }

    @Test
    public void testMinStack() {
        MinStack<Integer> stack = new MinStack<>();

        stack.push(3);
        Assert.assertEquals(3, (int) stack.minimum());

        stack.push(7);
        Assert.assertEquals(3, (int) stack.minimum());

        stack.push(2);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.push(73);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.push(5);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.pop();
        stack.pop();
        stack.pop();
        Assert.assertEquals(3, (int) stack.minimum());
    }
}

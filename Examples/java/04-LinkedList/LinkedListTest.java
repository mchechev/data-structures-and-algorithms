package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class LinkedListTest {
    @Test
    public void testLinkedList() {
        LinkedList<Integer> list = new LinkedList<>();

        list.addToBeginning(1);
        list.addToEnd(5);
        list.insertAt(4,1);
        list.insertAt(19, 2);
        Assert.assertEquals("[1, 4, 19, 5]", list.toString());

        list.reverse();
        Assert.assertEquals("[5, 19, 4, 1]", list.toString());

        list.eraseAt(1);
        list.eraseEnd();
        Assert.assertEquals("[5, 4]", list.toString());
    }
}

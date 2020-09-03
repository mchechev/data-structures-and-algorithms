package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class HashTableTest {
    @Test
    public void testHashTable() {
        HashTable<String, Integer> map = new HashTable<>();

        map.put("1", 1);
        map.put("2", 2);
        map.put("3", 3);
        map.put("4", 4);

        Assert.assertNull(map.get("7"));
        Assert.assertEquals(2, (int) map.get("2"));

        map.erase("3");

        Assert.assertEquals("{(1, 1), (2, 2), (4, 4)}", map.toString());
    }
}

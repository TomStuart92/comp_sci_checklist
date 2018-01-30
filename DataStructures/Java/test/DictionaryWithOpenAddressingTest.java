import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DictionaryWithOpenAddressingTest {
    @Test
    void shouldBeAbleToInsertAKeyValuePair() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
    }

    @Test
    void shouldBeAbleToInsertMultipleKeyValuePairs() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
        test.insert(2, 1);
        test.insert(3, 1);
    }

    @Test()
    void shouldThrowIfFull() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(2);
        test.insert(1, 1);
        test.insert(2, 1);
        Throwable exception = assertThrows(Error.class, () -> test.insert(3, 1));
        assertEquals("HashMap Full", exception.getMessage());
    }

    @Test
    void shouldBeAbleToGetAKeyValuePair() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
        assertEquals(new Integer(1), test.get(1));
    }

    @Test
    void shouldBeAbleToGetAKeyValuePairWhenManyPresent() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
        test.insert(2, 2);
        test.insert(3, 3);
        assertEquals(new Integer(1), test.get(1));
    }

    @Test
    void shouldBeAbleToTestIfKeyExists() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
        assertTrue(test.exists(1));
        assertFalse(test.exists(2));
    }

    @Test
    void shouldBeAbleToDeleteAKey() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(5);
        test.insert(1, 1);
        test.remove(1);
        assertFalse(test.exists(1));
    }

    @Test
    void shouldBeAbleToDeleteAKeyWithoutRemovingOtherEntries() {
        DictionaryWithOpenAddressing test = new DictionaryWithOpenAddressing(3);
        test.insert(1, 1);
        test.insert(2, 1);
        test.insert(3, 1);
        test.remove(1);
        assertFalse(test.exists(1));
        assertTrue(test.exists(2));
        assertTrue(test.exists(3));
    }
}
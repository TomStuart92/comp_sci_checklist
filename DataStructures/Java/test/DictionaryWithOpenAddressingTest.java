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
        assertEquals(1, test.get(1));
    }
}
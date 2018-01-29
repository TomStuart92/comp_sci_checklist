import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniversalHashTest {
    @Test
    void shouldReturnANumberInTheRange0ToArraySize() {
        int arraySize = 5;
        int key = 1;
        UniversalHash test = new UniversalHash(arraySize);
        int hashValue = test.hash(key);
        assertTrue(hashValue >= 0);
        assertTrue(hashValue < arraySize);
    }
}
import org.junit.jupiter.api.Test;

import java.util.HashMap;

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

    @Test
    void shouldGiveARelativelyEvenDistributionOfKeys() {

        int arraySize = 2;
        UniversalHash test = new UniversalHash(arraySize);
        HashMap<Integer, Integer> hm = new HashMap<>();

        for(int i = 0; i < 1000; i++) {
            int hashValue = test.hash(i);
            if(!hm.containsKey(hashValue))
                hm.put(hashValue, 1);
            else
                hm.put(hashValue,hm.get(hashValue)+1);
        }
        // we expect less than a 1/1000 i.e 0.1% preference of one key over another
        assertTrue(Math.abs(hm.get(0) - hm.get(1)) < 1);
    }
}
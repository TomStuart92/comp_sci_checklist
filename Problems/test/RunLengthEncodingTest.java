import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RunLengthEncodingTest {

    @Test
    void itShouldEncodeAString() {
        assertEquals("4A3B2C1D2A", RunLengthEncoding.encode("AAAABBBCCDAA"));
    }

    @Test
    void itShouldEncodeASingleCharString() {
        assertEquals("6A", RunLengthEncoding.encode("AAAAAA"));
    }

    @Test
    void itShouldEncodeGreaterThan10CharString() {
        assertEquals("12A", RunLengthEncoding.encode("AAAAAAAAAAAA"));
    }


    @Test
    void itShouldEncodeWhenEachCharAppearsOnceString() {
        assertEquals("1A1B1C1D1E1F", RunLengthEncoding.encode("ABCDEF"));
    }

    @Test
    void itShouldEncodeEmptyString() {
        assertEquals("", RunLengthEncoding.encode(""));
    }

    @Test
    void itShouldDecodeAString() {
        assertEquals("AAAABBBCCDAA", RunLengthEncoding.decode("4A3B2C1D2A"));
    }

    @Test
    void itShouldDecodeGreaterThan10CharString() {
        assertEquals("AAAAAAAAAAAA", RunLengthEncoding.decode("12A"));
    }

    @Test
    void itShouldDecodeEmptyString() {
        assertEquals("", RunLengthEncoding.decode(""));
    }


    @Test
    void encodeAndDecodeShouldReturnIdentity() {
        String test = "AAAABBBCCDAA";
        String encode = RunLengthEncoding.encode(test);
        String decode = RunLengthEncoding.decode(encode);
        assertEquals(test, decode);
    }

}
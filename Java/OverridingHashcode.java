import java.util.Objects;
/*
Rule 12. If overriding Object.equals overide Object.hashcode as well.

- If you override the equals method for class, you need to override hashcode to ensure Hashmap works. 
- The key provision is that equal objects must have equal hashcodes.
- Then unequal objects should produce distinct hashcodes. 

- Its important to try and use as much information from the class as possible to maximise the spread of instances.
    - Strings used to create hashcodes based on 16 randomly choosen characters. 
    - For large similar sets this makes the key space small.
*/

class OverridingHashcode {
    private Short areaCode;
    private Short prefix;
    private Short lineNum;

    // this is an awful implementation because of performance implications for hashMaps etc.
    // turns linear operations into quadratic ones. 

    public int badHashCode() {
        return 42;
    }

    // this implementation has pretty bad performance. Only use if not an issue. 
    public int mediocreHashCode() {
        return Objects.hash(lineNum, prefix, areaCode);
    }

    // this is a good implementation. 31 is chosen as an odd prime to prevent overflows.
    @Override
    public int hashCode() { 
        int result = Short.hashCode(areaCode);
        result = 31 * result + Short.hashCode(prefix);
        result = 31 * result + Short.hashCode(lineNum);
        return result;
    }

    // if cost of calculation of hashcode is significant, lazy initialize:
    private int hashCode;
    public int lazyHashCode() {
        int result = hashCode;
        if (result == 0) {
            result = Short.hashCode(areaCode);
            result = 31 * result + Short.hashCode(prefix);
            result = 31 * result + Short.hashCode(lineNum);
             hashCode = result;
        }
        return result;
    }


}
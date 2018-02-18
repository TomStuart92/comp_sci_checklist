import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/*
Rule 9. Prefer Try With Resources

Advantages: 
    - Ensures resources are cleared up properly.
    - Deals with exceptions in finally block.
    - Cleaner code.

Disadvantages:
    - Resources must implement AutoClosable Interface.
*/

class TryWithResources {
    // try-finally is not the best way to do it:
    static String firstLineOfFile(String path) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(path));
        try {
            return br.readLine();
        } finally {
            br.close();
        }
    }

    //instead use a tryWithResources block:
    static String otherFirstLineOfFile(String path) throws IOException {
        try(BufferedReader br = new BufferedReader(new FileReader(path))) {
            return br.readLine();
        }
    }
}
import org.apache.commons.math3.primes.Primes;
import java.util.concurrent.ThreadLocalRandom;

public class UniversalHash {
    private int a;
    private int b;
    private int largePrime;
    private int arraySize;

    UniversalHash(int arraySize) {
        this.largePrime = Primes.nextPrime(arraySize);
        this.a = ThreadLocalRandom.current().nextInt(1, this.largePrime);
        this.b = this.largePrime - this.a;
        this.arraySize = arraySize;
    }

    public int hash(int key) {
        return (((this.a * key + this.b) % this.largePrime) % (this.arraySize));
    }
}
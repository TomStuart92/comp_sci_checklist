import org.apache.commons.math3.primes.Primes;

import java.util.concurrent.ThreadLocalRandom;

class DictionaryWithOpenAddressing {
    private UniversalHash hashFunction;
    private DictionaryEntry[] data;
    private int capacity;

    DictionaryWithOpenAddressing(int capacity) {
        this.capacity = capacity;
        this.data = new DictionaryEntry[capacity];
        this.hashFunction = new UniversalHash(capacity);
    }

    public void insert(int key, int value) {
        DictionaryEntry newEntry = new DictionaryEntry(key, value);
        this.attemptInsert(newEntry, 0);
    }

    public int get(int key) {
        return this.attemptGet(key, 0);
    }

    private int attemptGet(int key, int trial) throws Error {
        if (trial >= this.capacity) {
            throw new Error("Key Not Found");
        }
        int hashCode = (this.hashFunction.hash(key) + trial) % (this.capacity);
        if (this.data[hashCode] == null) {
            return this.data[hashCode].value();
        }
        return this.attemptGet(key, trial + 1);
    }

    private void attemptInsert(DictionaryEntry entry, int trial) throws Error {
        if (trial >= this.capacity) {
            throw new Error("HashMap Full");
        }
        int hashCode = (this.hashFunction.hash(entry.key) + trial) % (this.capacity);

        if (this.data[hashCode] == null) {
            this.data[hashCode] = entry;
            return;
        }
        this.attemptInsert(entry, trial + 1);
    }

    private class DictionaryEntry {
        private int key;
        private int value;
        private boolean isDeleted;

        DictionaryEntry(int key, int value) {
            this.key = key;
            this.value = value;
            this.isDeleted = false;
        }

        public void setDeleted() {
            this.isDeleted = true;
        }

        public int key() {
            return this.key;
        }

        public int value() {
            return this.value;
        }

    }
}

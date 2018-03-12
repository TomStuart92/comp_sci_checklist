class DictionaryWithOpenAddressing {
    private UniversalHash hashFunction;
    private DictionaryEntry[z] data;
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

    public Integer get(int key) {
        Integer index = this.attemptGet(key, 0);
        if (index != null)
            return this.data[index].value();
        return null;
    }

    public void remove(int key) {
        Integer index = this.attemptGet(key, 0);
        if (index == null)
            throw new Error("Key Does Not Exist");
        this.data[index] = new DictionaryEntry(null, null);
    }

    public boolean exists(int key) {
        return this.get(key) != null;
    }

    private Integer attemptGet(int key, int trial) throws Error {
        if (trial > this.capacity) {
            return null;
        }
        int hashCode = (this.hashFunction.hash(key) + trial) % (this.capacity);
        DictionaryEntry entry = this.data[hashCode];
        if (entry == null)
            return null;
        if (entry.key() == null || entry.key() != key)
            return this.attemptGet(key, trial + 1);
        return hashCode;
    }

    private void attemptInsert(DictionaryEntry entry, int trial) throws Error {
        if (trial >= this.capacity) {
            throw new Error("HashMap Full");
        }
        int hashCode = (this.hashFunction.hash(entry.key) + trial) % (this.capacity);

        if (this.data[hashCode] == null || this.data[hashCode].key() == null) {
            this.data[hashCode] = entry;
            return;
        }
        this.attemptInsert(entry, trial + 1);
    }

    private class DictionaryEntry {
        private Integer key;
        private Integer value;

        DictionaryEntry(Integer key, Integer value) {
            this.key = key;
            this.value = value;
        }

        Integer key() {
            return this.key;
        }

        Integer value() {
            return this.value;
        }

    }
}

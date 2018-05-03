package src;

import java.util.LinkedHashMap;
import java.util.Map;

public class SimpleCache <K, V> extends LinkedHashMap<K, V> {
    private final int cacheSize;
    private static final long serialVersionUID = 42L;
    
    private SimpleCache(int cacheSize) {
        super();
        this.cacheSize = cacheSize;
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry eldest) {
        return size() > cacheSize;
    }

    public static void main(String[] args) {
        SimpleCache<Integer, Integer> test = new SimpleCache<>(1);
        test.put(1, 1);
        test.put(2, 2);
        System.out.println(test.containsKey(1));
        System.out.println(test.containsKey(2));
        test.put(3, 3);
        System.out.println(test.containsKey(2));
    }
}

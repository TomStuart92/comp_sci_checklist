/*
Rule 7. Eliminate obsolete objects references

While the majority of objects in Java are garbage collected,
with arrays we can maintain references to objects we no longer need.
Make sure to explictly dereference by setting to null.

This is only needed when a class manages its own memory.
For example below, only the user knows which portion of the array is important

Other commons sources of mem leaks are caches and listeners/callbacks.
Both of these involve putting something into memory for an future event at an unknown time.
If no action is taken these will accumulate over time. 
Both should be periodically cleaned out.
*/

import java.util.Arrays;
import java.util.EmptyStackException;

public class EliminateObsoleteRefs {
    public class Stack {
        private Object[] elements;
        private int size;
        private int capacity;
        private static final int DEFAULT_INITIAL_CAPACITY = 16;

        public Stack() {
            size = 0;
            capacity = DEFAULT_INITIAL_CAPACITY;
            elements = new Object[capacity];
        }

        public void push(Object e) {
            ensureCapacity();
            elements[size++] = e;
        }

        // this leaks as references remain in region size -> capacity
        public Object leakyPop() {
            if(size == 0)
                throw new EmptyStackException();
            return elements[--size];
        }

        // by nulling refs we ensure objects are garbage collected
        public Object pop() {
            if(size == 0)
                throw new EmptyStackException();
            Object result = elements[--size];
            elements[size] = null;
            return result;
        }

        private void ensureCapacity() {
            if(elements.length == size)
                capacity = 2 * capacity + 1;
                elements = Arrays.copyOf(elements, capacity);
        }
    }
}

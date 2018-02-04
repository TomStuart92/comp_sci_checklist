/*
Rule 4. Enforce noninstantiability with a private constructor

For classes which are a collection of static methods, i.e. are never meant to be instantiated,
Explicitly make the constructor private otherwise Java will create a parameterless default constructor.
*/


public class PrivateConstructor {
    private PrivateConstructor() {
        // throw error to ensure class is never instantiated.
        throw new AssertionError();
    }
    public static void foo() {
        System.out.println("Bar");
    }
}
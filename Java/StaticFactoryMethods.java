/*
Rule 1. Consider Static Factory Methods Instead Of Constructors.

Advantages: 
    - Can have named methods unlike constructors.
    - Do not need to return a new instance (can use singleton).
    - Can return any subtype of their return type.
    - Return type can vary as function of input
    - Return class need not exist when method is written

Disadvantages:
    - Classes without a public constructor cannot be subclassed.
*/


public class StaticFactoryMethods {
    public static Boolean valueOf(Boolean b) {
        // return singleton instances of Booleans.
        return b ? Boolean.TRUE : Boolean.FALSE;
    }
}
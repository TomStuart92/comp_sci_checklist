import java.util.List;
import java.util.ArrayList;
/*
Rule 26. Don't use raw types with Generics

Three types of generics:
List<E> -> Generic Type
List<String> -> Parameterized Type
List -> Raw Type

Using raw types means you lose all the safety and expressiveness beneifts of generics.

If you need a generic with no restriction on type use a unbounded wilcard type List<?> instead of the raw type.
*/ 

class GenericTypes {
  // because list here is raw type not parameterized we loose compile time checking. 
  private static void unsafeAdd(List list, Object o) {
    list.add(o);
  }

  // adding types provides compile time checks. 
  private static void safeAdd(List<Object> list, Object o) {
    list.add(o);
  }
  
  // this fails at runtime as we don't have type checking. 
  public static void main(String[] args) {
    List<String> strings = new ArrayList<>();
    unsafeAdd(strings, Integer.valueOf(42));
    String s = strings.get(0);
  }
}
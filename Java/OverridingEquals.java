import java.util.Objects;

import OverridingEquals.CaseInsensitiveString;


/*
Rule 11. Obey the general contract when overriding Object.equals

Don't override when:
- Each instance of a class is inherently unique. i.e. Thread
- There is no need to compare a equality test. Does your object need to be compared to another?
- A superclass already implements equals and the inherited behavior is appropriate. 
- The class is private/package-private and equals will never be needed. 

Override when:
- A class has a notion of logical equality, mostly value based classes

Obey the general contract so that equality is:
- Reflexive: x.equals(x)
- Symmetric: if x.equals(y) then y.equals(x)
- Transitive: if x.equals(y) && y.equals(z) then x.equals(z);
- Consistent: if x.equals(y) then x must always equal y.
- Handle Nulls: x.equals(null) => false
*/

class OverridingEquals {

    public final class CaseInsensitiveString {
        private final String s;

        public CaseInsensitiveString(String s) {
            this.s = Objects.requireNonNull(s);
        }

        // breaks symmetry as doesn't deal with String case being lowercased.
        @Override
        public boolean equals(Object o) {
            if(o instanceof OverridingEquals)
                return s.equalsIgnoreCase(((CaseInsensitiveString) o).s);
            if(o instanceof String)
                return s.equalsIgnoreCase((String) o);
            return false;
        }
    }

    public class Point {
        private final int x;
        private final int y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Point))
                return false;
            Point p = (Point) o;
            return p.x == this.x && p.y == this.y;
        }
    }
}
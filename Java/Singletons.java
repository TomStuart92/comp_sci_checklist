/*
Rule 3. Enforce Singleton property with a private constructor

Advantages: 
    - Guarantees only one instance can be in existence at any one time

Disadvantages:
    - Difficult to test
*/


public class Singletons {

    // Singleton with public final field
    public class Elvis {
        public final Elvis INSTANCE = new Elvis();
        private Elvis() {

        }
        public void leaveTheBuilding() {

        }
    }

    // Singleton with static factory
    public class AnotherElvis {
        public final AnotherElvis INSTANCE = new AnotherElvis();
        private AnotherElvis() {}
        public AnotherElvis getInstance() { return INSTANCE; }
        public void leaveTheBuilding() {
        }
    }

    // Preferred method
    // Singleton with enum (protects against deserialization making many instances.)
    public enum FinalElvis {
        INSTANCE;
        public void leaveTheBuilding() {}
    }
}
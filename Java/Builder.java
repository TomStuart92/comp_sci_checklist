/*
Rule 2. Consider a builder when faced with many parameters

Advantages: 
    - Allows clear setting of many parameters
    - Avoids inconsistent state of JavaBeans patterns

Disadvantages:
    - Additional overhead of builder instance 
    - More verbose
*/


public class Builder {
    public class NutritionFacts {
        private final int servingSize;
        private final int servings;
        private final int calories;
        private final int fat;
        private final int sodium;
        private final int carbohydrate;
        
        public class NutritionFactsBuilder {
            //required fields
            private final int servingSize;
            private final int servings;

            //optional fields - defaults to
            private int calories = 0;
            private int fat = 0;
            private int sodium = 0;
            private int carbohydrate = 0;

            public NutritionFactsBuilder(int servingSize, int servings) {
                this.servingSize = servingSize;
                this.servings = servings;
            }

            public NutritionFactsBuilder calories(int val) {
                calories = val;
                return this;
            }
            public NutritionFactsBuilder fat(int val) {
                fat = val;
                return this;
            }
            public NutritionFactsBuilder sodium(int val) {
                sodium = val;
                return this;
            }
            public NutritionFactsBuilder carbohydrate(int val) {
                carbohydrate = val;
                return this;
            }

            public NutritionFacts build(){
                return new NutritionFacts(this);
            }
        }

        private NutritionFacts(NutritionFactsBuilder builder) {
            servingSize = builder.servingSize;
            servings = builder.servings;
            calories = builder.calories;
            fat = builder.fat;
            sodium = builder.sodium;
            carbohydrate = builder.carbohydrate;
        }
    }
}
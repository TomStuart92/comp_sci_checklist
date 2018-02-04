import java.util.Collection;
import java.util.Objects;
import java.util.Vector;

/*
Rule 5. Use dependency injection when a class depends on another class

Advantages: 
    - Allows easy testing.
    - Makes code more reusable. 
*/


public class DependencyInjection {
    
    public class SpellChecker {
        private final Lexicon dictionary;

        public SpellChecker(Lexicon dictionary) {
            this.dictionary = Objects.requireNonNull(dictionary);
        }

        public boolean isValid(String word) {
            return this.dictionary.contains(word); 
        }

        public Vector<String> suggestions(String typo) {
            return this.dictionary.match(typo);
        }
    }

    public class Lexicon {
        private final Vector<String> words = new Vector<>();
        
        public boolean contains(String word) {
            return this.words.contains(word);
        }

        public Vector<String> match(String word) {
            return this.words;
        }
    }
}
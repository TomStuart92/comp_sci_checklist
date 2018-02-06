import java.util.regex.Pattern;
/*
Rule 6. Avoid creating unnecessary objects

Be careful about creating unnecessary object. Reuse where possible:
*/

public class UnnecessaryObjects {
    
    static boolean slowString() {
        //don't declare like this as create new instance:
        String s = new String("Bikini");

        //instead resuse instances:
        String t = "bikini";
        
        return s == t;
    }

    // has to create expensive regexp everytime method is called.
    static boolean slowIsRomanNumeral(String s) {
        return s.matches("complicated regexp");
    }

    //instead store regexp in final field, up to 6.5x faster
    private static final Pattern ROMAN = Pattern.compile("complicated regexp");
    static boolean fastIsRomanNumberal(String s) {
        return ROMAN.matcher(s).matches();
    }

    //Really slow due to creation of Long instead of long
    //Creates 2^31 Long instances
    private static long sum() {
        Long sum = 0L;
        for(long i = 0; i <= Integer.MAX_VALUE; i++ )
            sum += i;
        return sum;
    }
}

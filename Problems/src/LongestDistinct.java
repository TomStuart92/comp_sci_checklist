package src;// Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
// For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

class LongestDistinct {
    private static final int CHAR_COUNT = 26;

    //  validates string has enough unique characters remaining.
    private static Boolean isValid(int count[], int k) {
        int val = 0;
        for (int i = 0; i < CHAR_COUNT; i++) {
            if(count[i] > 0)
                    val++;
        }
        return k >= val;
    }

    //  returns the length of the longest substring
    private static int kUniques(String s, int k) {
        int u = 0;             // the number of unique chars in string.
        int n = s.length();    // length of string s
        int count[] = new int[CHAR_COUNT]; // array to hold char counts in string.

        // traverse the string and fill the array with chars.
        for (int i = 0; i< n; i++) {
            if (count[s.charAt(i) - 'a'] == 0)
                u++;
            count[s.charAt(i) - 'a']++;
        }

        // check we have enough unique chars in string.
        if (u < k) {
            throw new Error("Not Enough Unique Characters in String s");
        }

        int curr_start = 0;
        int curr_end = 0;
        int max_window_size = 1;
        int max_window_start = 0;

        count = new int[CHAR_COUNT]; // reset to zeros
        count[s.charAt(0) - 'a']++;  // add first char

        for (int i=1; i < n; i++) {
            // add next character;
            count[s.charAt(i) - 'a']++;
            curr_end++;

            // if there are more than k unique characters in current window
            // remove from left hand side
            while(!isValid(count, k)) {
                count[s.charAt(curr_start) - 'a']--;
                curr_start++;
            }

            // update max window size if needed
            if(curr_end - curr_start + 1 > max_window_size) {
                max_window_size = curr_end - curr_start + 1;
                max_window_start = curr_start;
            }
        }

        return max_window_size;
    }

    public static void main(String[] args) {
        int result = LongestDistinct.kUniques("abcba", 2);
        System.out.println("Result: " + result);
    }
}
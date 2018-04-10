public class RunLengthEncoding {
    static String encode(String string) {
        if (string.isEmpty()) {
            return string;
        }
        char current = string.charAt(0);
        int count = 0;
        StringBuilder builder = new StringBuilder();

        for(int i = 0; i < string.length(); i++) {
            if(string.charAt(i) != current) {
                builder.append(count);
                builder.append(current);
                current = string.charAt(i);
                count = 1;
            }
            else {
                count++;
            }
        }
        builder.append(count);
        builder.append(current);
        return builder.toString();
    }

    static String decode(String string) {
        if (string.isEmpty()) {
            return string;
        }
        int count = 0;
        StringBuilder builder = new StringBuilder();

        for(int i = 0; i < string.length(); i++) {
            if(Character.isDigit(string.charAt(i))) {
                count = count * 10 + Character.getNumericValue(string.charAt(i));
            } else {
                String repeat = repeat(string.charAt(i), count);
                builder.append(repeat);
                count = 0;
            }
        }
        return builder.toString();

    }

    private static String repeat(char c, int times) {
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < times; i++) {
            builder.append(c);
        }
        return builder.toString();
    }

}

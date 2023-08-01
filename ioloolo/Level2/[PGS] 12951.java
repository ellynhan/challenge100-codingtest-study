class Solution {
    public String solution(String s) {
        char[] chars = s.toCharArray();

        for (int i = 0; i < chars.length; ++i) {
            if (chars[i] == ' ' || Character.isDigit(chars[i])) {
                continue;
            }

            if (i == 0) {
                chars[i] = Character.toUpperCase(chars[i]);
                continue;
            }

            if (chars[i-1] == ' ') {
                chars[i] = Character.toUpperCase(chars[i]);
            } else {
                chars[i] = Character.toLowerCase(chars[i]);
            }
        }

        return new String(chars);
    }
}
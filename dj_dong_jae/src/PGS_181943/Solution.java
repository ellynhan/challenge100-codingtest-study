package PGS_181943;

public class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        char[] originalArray = my_string.toCharArray();
        char[] overwriteArray = overwrite_string.toCharArray();

        for (int i = 0; i < overwriteArray.length; i++) {
            originalArray[i+s] = overwriteArray[i];
        }

        StringBuilder sb = new StringBuilder();
        for (char c : originalArray) {
            sb.append(c);
        }

        return sb.substring(0);
    }
}

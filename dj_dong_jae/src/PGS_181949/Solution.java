package PGS_181949;

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();

        Character[] chars = new Character[a.length()];
        for (int i = 0; i < a.length(); i++) {
            if (Character.isLowerCase(a.charAt(i))) {
                chars[i] = Character.toUpperCase(a.charAt(i));
            } else {
                chars[i] = Character.toLowerCase(a.charAt(i));
            }
        }

        StringBuilder sb = new StringBuilder();

        for (char c : chars) {
            sb.append(c);
        }

        String result = sb.toString();

        System.out.println(result);
    }
}

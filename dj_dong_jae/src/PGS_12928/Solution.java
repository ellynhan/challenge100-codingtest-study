package PGS_12928;

import java.util.*;

public class Solution {
    public static List<Integer> array = new ArrayList<>();
    public static int sum = 0;

    public int solution(int n) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                array.add(i);
            }
        }

        for (int x : array) {
            sum += x;
        }

        return sum;
    }
}

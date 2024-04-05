package BOJ_2018;

import java.util.*;

public class Main {
    public static long n;
    public static long sum = 1, count = 1, startIndex = 1, endIndex = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextLong();

        while (endIndex != n) {
            if (sum == n) {
                count++;
                endIndex++;
                sum += endIndex;
            } else if (sum > n) {
                sum -= startIndex;
                startIndex++;
            } else {
                endIndex++;
                sum += endIndex;
            }
        }

        System.out.println(count);
    }
}

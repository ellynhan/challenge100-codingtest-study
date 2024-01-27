package BOJ_10773;

import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static Stack<Integer> stack = new Stack<>();
    public static int n, result = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (x == 0) stack.pop();
            else stack.push(x);
        }

        while (!stack.isEmpty()) {
            result += stack.pop();
        }

        System.out.println(result);
    }

}

package BOJ_10828;

import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            switch (str) {
                case "push":
                    stack.push(sc.nextInt());
                    break;
                case "pop":
                    if (!stack.isEmpty()) {
                        int x = stack.pop();
                        result.append(x).append("\n");
                    } else {
                        result.append("-1").append("\n");
                    }
                    break;
                case "size":
                    result.append(stack.size()).append("\n");
                    break;
                case "empty":
                    if (stack.isEmpty()) {
                        result.append("1").append("\n");
                    } else {
                        result.append("0").append("\n");
                    }
                    break;
                case "top":
                    if (stack.isEmpty()) {
                        result.append("-1").append("\n");
                    } else {
                        result.append(stack.peek()).append("\n");
                    }
                    break;
            }
        }

        System.out.println(result);

    }

}

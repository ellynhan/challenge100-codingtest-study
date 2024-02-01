package BOJ_9012;

import java.util.*;

public class Main {

    public static int t = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        sc.nextLine();
        boolean[] result = new boolean[t];
        for (int i = 0; i < t; i++) {
            String str = sc.nextLine();
            Stack<Character> stack = new Stack<>();
            for (int j = 0; j < str.length(); j++) {
                char now = str.charAt(j);
                if (now == '(') {
                    stack.push(now);
                }
                if (now == ')') {
                    if (!stack.isEmpty()){
                        char pair = stack.pop();
                        if (pair != '(') {
                            result[i] = false;
                            break;
                        } else {
                            result[i] = true;
                        }
                    } else {
                        result[i] = false;
                        break;
                    }
                }
            }
            if (result[i]) {
                if (!stack.isEmpty()) result[i] = false;
            }
        }

        for (Boolean ans : result) {
            if (ans) System.out.println("YES");
            else System.out.println("NO");
        }

    }

}

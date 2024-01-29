package BOJ_5430;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

    public static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder result = new StringBuilder();

    public static void main(String[] args) throws IOException {

        int t = Integer.parseInt(reader.readLine());
        while (t --> 0) {
            String command = reader.readLine();
            int n = Integer.parseInt(reader.readLine());

            String input = reader.readLine();
            String[] strArray = input.substring(1, input.length() - 1).split(",");
            ArrayDeque<Integer> deque = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                deque.add(Integer.parseInt(strArray[i]));
            }
            AC(command, deque);
        }
        System.out.println(result);
        reader.close();
    }

    public static void AC(String command, ArrayDeque<Integer> deque) {
        boolean isRight = true;
        boolean flag = true;

        outerLoop:
        for (int i = 0; i < command.length(); i++) {
            char now = command.charAt(i);
            switch (now) {
                case 'R':
                    isRight = !isRight;
                    break;
                case 'D':
                    if (!deque.isEmpty()) {
                        if (isRight) deque.pollFirst();
                        else deque.pollLast();
                    } else {
                        flag = false;
                        break outerLoop;
                    }
                    break;
            }
        }

        if (flag) {
            if (!deque.isEmpty()) {
                result.append("[");
                if (isRight) {
                    for (int x : deque) {
                        result.append(x).append(",");
                    }
                } else {
                    while(!deque.isEmpty()) {
                        result.append(deque.pollLast()).append(",");
                    }
                }
                result.deleteCharAt(result.length() - 1);
                result.append("]").append("\n");
            } else {
                result.append("[]").append("\n");
            }
        } else {
            result.append("error").append("\n");
        }
    }

}
package BOJ_10845;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {

    public static StringBuilder result = new StringBuilder();
    public static ArrayDeque<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < t; i++) {
            String str = sc.next();
            switch (str) {
                case "push":
                    q.add(sc.nextInt());
                    break;
                case "pop":
                    if (q.isEmpty()) {
                        result.append("-1").append("\n");
                    } else {
                        result.append(q.pollFirst()).append("\n");
                    }
                    break;
                case "size":
                    result.append(q.size()).append("\n");
                    break;
                case "empty":
                    if (q.isEmpty()) {
                        result.append("1").append("\n");
                    } else {
                        result.append("0").append("\n");
                    }
                    break;
                case "front":
                    if (q.isEmpty()) {
                        result.append("-1").append("\n");
                    } else {
                        result.append(q.peekFirst()).append("\n");
                    }
                    break;
                case "back":
                    if (q.isEmpty()) {
                        result.append("-1").append("\n");
                    } else {
                        result.append(q.peekLast()).append("\n");
                    }
                    break;
            }
        }
        System.out.println(result);
    }

}

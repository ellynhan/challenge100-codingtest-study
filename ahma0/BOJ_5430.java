import java.io.*;
import java.util.*;

public class Main {
    static Deque<String> deque;
    static StringBuilder sb = new StringBuilder();
    static boolean isRight = false;       //오른쪽 것을 뺍니까?

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        deque = new LinkedList<>();

        for(int i = 0; i < T; i++) {
            String temp = br.readLine();
            int n = Integer.parseInt(br.readLine());

            String input = br.readLine().replace("[", "").replace("]", "");

            if(n == 0 && temp.contains("D")) {
                sb.append("error\n");
                continue;
            }

            deque.addAll(Arrays.asList(input.split(",")));

            AC(temp);
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    static void AC(String temp) {
        isRight = false;

        for(int j = 0; j < temp.length(); j++) {
            if(temp.charAt(j) == 'R') {
                isRight = !isRight;
                continue;
            }

            if(deque.isEmpty()) {
                sb.append("error\n");
                return;
            }

            if(isRight)
                deque.removeLast();
            else
                deque.removeFirst();

        }

        print();

    }

    static void print() {
        sb.append("[");

        if(deque.size() > 0) {
            if(isRight) {
                sb.append(deque.pollLast());
                while (!deque.isEmpty())
                    sb.append(",").append(deque.pollLast());
            }
            else {
                sb.append(deque.pollFirst());
                while (!deque.isEmpty())
                    sb.append(",").append(deque.pollFirst());
            }
        }

        sb.append("]\n");

    }

}
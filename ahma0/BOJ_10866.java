import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        Deque<Integer> deque = new LinkedList<>();

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            switch (st.nextToken()) {
                case "push_front":
                    deque.addFirst(Integer.parseInt(st.nextToken()));
                    break;
                case "push_back":
                    deque.add(Integer.parseInt(st.nextToken()));
                    break;
                case "pop_front":
                    if(!deque.isEmpty())
                        sb.append(deque.removeFirst()).append("\n");
                    else sb.append(-1).append("\n");
                    break;
                case "pop_back":
                    if(!deque.isEmpty())
                        sb.append(deque.removeLast()).append("\n");
                    else sb.append(-1).append("\n");
                    break;
                case "size":
                    sb.append(deque.size()).append("\n");
                    break;
                case "empty":
                    sb.append(deque.isEmpty() ? 1 : 0).append("\n");
                    break;
                case "front":
                    if(!deque.isEmpty())
                        sb.append(deque.peekFirst()).append("\n");
                    else sb.append(-1).append("\n");
                    break;
                case "back":
                    if(!deque.isEmpty())
                        sb.append(deque.peekLast()).append("\n");
                    else sb.append(-1).append("\n");
                    break;

            }

        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }
}

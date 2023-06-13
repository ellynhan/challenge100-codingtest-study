import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int last = 0;

        Queue<Integer> queue = new LinkedList<>();

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            switch (st.nextToken()) {
                case "push":
                    last = Integer.parseInt(st.nextToken());
                    queue.add(last);
                    break;
                case "pop":
                    if(!queue.isEmpty())
                        sb.append(queue.poll() + "\n");
                    else sb.append(-1 + "\n");
                    break;
                case "size":
                    sb.append(queue.size() + "\n");
                    break;
                case "empty":
                    sb.append((queue.isEmpty() ? 1 : 0) + "\n");
                    break;
                case "front":
                    if(!queue.isEmpty())
                        sb.append(queue.peek() + "\n");
                    else sb.append(-1 + "\n");
                    break;
                case "back":
                    if(!queue.isEmpty())
                        sb.append(last + "\n");
                    else sb.append(-1 + "\n");
                    break;

            }

        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}

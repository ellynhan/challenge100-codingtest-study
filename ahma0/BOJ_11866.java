import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Integer> queue = new LinkedList<>();

        sb.append("<");

        for(int i = 1; i <= N; i++)
            queue.add(i);

        int cnt = 1;
        while(!queue.isEmpty()) {
            if(cnt != K) {
                cnt++;
                queue.add(queue.poll());
            }
            else {
                cnt = 1;
                sb.append(queue.poll()).append(", ");
            }
        }

        sb.setLength(sb.length() - 2);
        sb.append(">");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}
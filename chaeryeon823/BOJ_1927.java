import java.io.*;
import java.util.PriorityQueue;

/**
 * [BOJ] 1927 / 최소 힙 / 실버2
 */
public class BOJ_1927 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(br.readLine());

            if (tmp == 0) {
                if(priorityQueue.isEmpty()) {
                    bw.write("0\n");
                }
                else {
                    bw.write(priorityQueue.poll() + "\n");

                }
            }
            else {
                priorityQueue.add(tmp);

            }

        }

        bw.flush();
        bw.close();
        br.close();
    }
}

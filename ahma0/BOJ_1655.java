import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq1 = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> pq2 = new PriorityQueue<>();

        for(int i = 0; i < N; i++) {
            int t = Integer.parseInt(br.readLine());

            if(pq1.size() == pq2.size() || pq1.isEmpty())
                pq1.add(t);
            else
                pq2.add(t);

            if(!pq2.isEmpty() && pq1.peek() > pq2.peek()) {
                pq2.add(pq1.poll());
                pq1.add(pq2.poll());
            }

            sb.append(pq1.peek()).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}


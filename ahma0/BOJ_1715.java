import java.io.*;
import java.util.PriorityQueue;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        if(N == 1) {
            sb.append(0).append("\n");
            bw.write(sb.toString());
            bw.flush();
            bw.close();
            br.close();
            return;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i = 0; i < N; i++)
            pq.add(Integer.parseInt(br.readLine()));

        int sum = 0;

        while(pq.size() > 1) {
            int temp1 = pq.poll();
            int temp2 = pq.poll();

            sum += temp1 + temp2;

            pq.add(temp1 + temp2);
        }

        sb.append(sum).append("\n");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}
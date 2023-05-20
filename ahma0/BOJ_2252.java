import java.io.*;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        LinkedList<Integer>[] list = new LinkedList[N + 1];
        int dig[] = new int[N + 1];

        for(int i = 0; i < list.length; i++)
            list[i] = new LinkedList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            list[A].add(B);
            dig[B]++;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        boolean visited[] = new boolean[N + 1];

        for(int i = 1; i < dig.length; i++)
            if(dig[i] == 0)
                pq.add(i);

        while(!pq.isEmpty()) {
            int t = pq.poll();
            visited[t] = true;
            sb.append(t + " ");

            for(Integer n : list[t]) {
                dig[n]--;

                if(dig[n] == 0 && !visited[n])
                    pq.add(n);
            }
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}

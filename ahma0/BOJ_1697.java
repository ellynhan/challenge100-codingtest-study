import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    static int[] visited = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        sb.append(bfs(N)).append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

    static int bfs(int node) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(node);
        visited[node] = 1;

        int move[] = new int[3];

        while(!queue.isEmpty()) {
            int n = queue.poll();

            if(n == K)
                return visited[n] - 1;

            move[0] = n - 1;
            move[1] = n + 1;
            move[2] = n * 2;

            for(int i = 0; i < 3; i++) {
                if(move[i] >= 0 && move[i] <= 100000 && visited[move[i]] == 0) {
                    visited[move[i]] = visited[n] + 1;
                    queue.add(move[i]);
                }
            }
        }

        return -1;
    }

}
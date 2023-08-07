import java.io.*;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M, x, y;
    static LinkedList<Integer>[] graph;
    static boolean visited[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        M = Integer.parseInt(br.readLine());

        graph = new LinkedList[N + 1];

        for(int i = 0; i <= N; i++)
            graph[i] = new LinkedList<>();

        visited = new boolean[N + 1];

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            graph[p].add(c);
            graph[c].add(p);
        }

        sb.append(search()).append("\n");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

    static int search() {
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(x, 0));
        visited[x] = true;

        while(!queue.isEmpty()) {
            Node now = queue.poll();
            int to = now.to;

            if(to == y)
                return now.cnt;

            Iterator<Integer> iterator = graph[to].iterator();

            while(iterator.hasNext()) {
                int a = iterator.next();

                if(!visited[a]) {
                    queue.add(new Node(a, now.cnt + 1));
                    visited[a] = true;
                }
            }
        }

        return -1;
    }

    static class Node {
        int to;
        int cnt;

        public Node(int to, int cnt) {
            this.to = to;
            this.cnt = cnt;
        }
    }
}

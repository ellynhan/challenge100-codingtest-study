import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static LinkedList<Integer>[] graph;
    static boolean[] visited;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int t, w;

        graph = new LinkedList[N + 1];

        for(int i = 1; i < graph.length; i++)
            graph[i] = new LinkedList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            t = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            graph[t].add(w);
            graph[w].add(t);
        }

        arr = new int[N + 1];
        visited = new boolean[N + 1];

        bfs(R);

        for(int i = 1; i < arr.length; i++)
            System.out.println(arr[i]);

    }

    public static void bfs(int R) {
        int s, cnt = 0;
        Queue<Integer> queue = new LinkedList<>();

        visited[R] = true;
        queue.add(R);

        while(!queue.isEmpty()) {
            s = queue.poll();
            arr[s] = ++cnt;
            Collections.sort(graph[s], Collections.reverseOrder());
            Iterator<Integer> iterator = graph[s].iterator();

            while (iterator.hasNext()) {
                int t = iterator.next();
                if(!visited[t]) {
                    visited[t] = true;
                    queue.add(t);
                }
            }
        }
    }

}
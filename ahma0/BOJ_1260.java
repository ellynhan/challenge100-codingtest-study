import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static LinkedList<Integer>[] graph;
    static ArrayList<Integer>[] arrayLists = new ArrayList[2];
    static boolean visited[];
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int t, w;

        graph = new LinkedList[N + 1];
        for(int i = 1; i <= N; i++)
            graph[i] = new LinkedList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            t = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            graph[t].add(w);
            graph[w].add(t);
        }

        visited = new boolean[N + 1];

        for(int i = 0; i < arrayLists.length; i++)
            arrayLists[i] = new ArrayList<>();

        dfs(R);
        bfs(R);

        for(int i = 0; i < arrayLists.length; i++) {
            for(int j = 0; j < arrayLists[i].size(); j++)
                System.out.print(arrayLists[i].get(j) + " ");

            System.out.println();
        }
    }

    static void dfs(int R) {
        visited[R] = true;
        arrayLists[0].add(R);
        Collections.sort(graph[R]);
        Iterator<Integer> iterator = graph[R].iterator();

        while(iterator.hasNext()) {
            int t = iterator.next();
            if(!visited[t]) {
                dfs(t);
            }
        }
    }

    static void bfs(int R) {
        int t;

        Arrays.fill(visited, false);
        cnt = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(R);
        visited[R] = true;

        while(!queue.isEmpty()) {
            t = queue.poll();
            Iterator<Integer> iterator = graph[t].iterator();
            arrayLists[1].add(t);

            while(iterator.hasNext()) {
                int a = iterator.next();
                if(!visited[a]) {
                    queue.add(a);
                    visited[a] = true;
                }
            }
        }
    }

}
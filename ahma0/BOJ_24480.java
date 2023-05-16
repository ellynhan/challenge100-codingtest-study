import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int arr[];
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int t, w;

        LinkedList<Integer>[] list = new LinkedList[N + 1];
        arr = new int[N + 1];

        for(int i = 0; i < list.length; i++) {
            list[i] = new LinkedList<>();
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            t = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            list[t].add(w);
            list[w].add(t);
        }

        boolean visited[] = new boolean[N + 1];

        dfs(R, list, visited);

        for(int i = 1; i <= N; i++)
            System.out.println(arr[i]);
    }

    public static void dfs(int start, LinkedList[] graph, boolean[] visited) {
        Collections.sort(graph[start], Collections.reverseOrder());
        Iterator<Integer> iterator = graph[start].iterator();

        visited[start] = true;
        arr[start] = ++cnt;

        while(iterator.hasNext()) {
            int i = iterator.next();

            if(!visited[i])
                dfs(i, graph, visited);
        }
    }

}
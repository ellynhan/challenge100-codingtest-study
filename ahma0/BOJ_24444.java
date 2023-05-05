import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static LinkedList<Integer>[] linkedLists;
    static int N;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        int t, w;

        linkedLists = new LinkedList[N + 1];

        for(int i = 0; i <= N; i++)
            linkedLists[i] = new LinkedList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            t = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            linkedLists[t].add(w);
            linkedLists[w].add(t);
        }

        arr = new int[N + 1];

        bfs(R);

        for(int i = 1; i < arr.length; i++)
            System.out.println(arr[i]);

    }

    public static void bfs(int R) {
        int s, cnt = 0;
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[N + 1];

        queue.add(R);
        visited[R] = true;

        while(!queue.isEmpty()) {
            s = queue.poll();
            arr[s] = ++cnt;
            Collections.sort(linkedLists[s]);
            Iterator<Integer> iterator = linkedLists[s].iterator();

            while(iterator.hasNext()) {
                int n = iterator.next();
                if(!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

}
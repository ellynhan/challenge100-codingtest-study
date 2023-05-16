import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {

    static boolean visited[];
    static int cnt = 0;
    static LinkedHashMap<Integer, Integer> map = new LinkedHashMap<>();
    static LinkedList<Integer>[] graph;

    public static void dfs(int r) {
        Iterator<Integer> iter = graph[r].iterator();

        visited[r] = true;
        if(r != 0) cnt++;
        if(!map.containsKey(r)) map.put(r, cnt);

        while(iter.hasNext()) {
            int w = iter.next();
            if(!visited[w]) dfs(w);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        visited = new boolean[v + 1];
        Arrays.fill(visited, false);

        graph = new LinkedList[v + 1];

        for(int i = 0; i < graph.length; i++)
            graph[i] = new LinkedList<>();


        for(int i = 1; i <= e; i++) {
            st = new StringTokenizer(br.readLine());

            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());

            graph[v1].add(v2);
            graph[v2].add(v1);
        }

        for(int i = 0; i < v; i++)
            Collections.sort(graph[i]);

        dfs(r);

        StringBuilder sb = new StringBuilder();

        for(int i = 1; i <= v; i++) {
            if(!map.containsKey(i)) sb.append(0 + "\n");
            else sb.append(map.get(i) + "\n");
        }
        sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb);
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static int cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()), m = Integer.parseInt(br.readLine()), a, b;
        StringTokenizer st;

        int arr[][] = new int[n + 1][n + 1];

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        boolean visited[] = new boolean[n + 1];
        cnt = 0;

        bfs(1, arr, visited);

        System.out.println(cnt);

    }

    public static void bfs(int start, int graph[][], boolean visited[]) {
        visited[start] = true;

        for(int i = 1; i < graph.length; i++) {
            if(graph[start][i] == 1 && !visited[i]) {
                cnt++;
                bfs(i, graph, visited);
            }
        }
    }
}
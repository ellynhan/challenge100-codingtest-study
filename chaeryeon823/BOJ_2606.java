import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * [BOJ] 2606 / 바이러스 / 실버3
 */
public class BOJ_2606 {
    // 컴퓨터의 수( 노드의 수 )
    static int N;

    // 연결되어 있는 컴퓨터 쌍의 수( 간선의 수)
    static int M;

    static int answer = 0;

    static ArrayList<ArrayList<Integer>> graph;

    static int[] visited;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        visited = new int[N + 1];
        graph = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        // 그래프 그리기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // 양방향 그래프
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // DFS 시작
        DFS(1);

        // 첫번째 노드는 빼고 출력
        System.out.println(answer - 1);


    }

    static void DFS(int now) {

        // System.out.println(now);
        // 방문체크
        visited[now] = 1;
        answer++;

        // 다음 node 찾기
        for (int node : graph.get(now)) {
            // 방문하지 않았으면
            if (visited[node] == 0) {
                //방문하기
                DFS(node);
            }
        }

    }
}

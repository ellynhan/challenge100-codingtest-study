import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * [BOJ] 24479 / 알고리즘 수업 - 깊이우선 탐색 1 / 실버2
 */

public class BOJ_24479 {

    // 점점의 수
    static int N;

    // 간선의 수
    static int M;

    // 시작 정점
    static int R;

    static ArrayList<ArrayList<Integer>> graph;
    static int[] visited;

    static int[] answer;

    static int cnt = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        visited = new int[N + 1];
        answer = new int[N + 1];
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

        // 그래프 오름차순 정렬
        for (int i = 0; i < N; i++) {
            Collections.sort(graph.get(i));
        }

        // DFS 시작
        DFS(R);

        // answer 배열 출력
        for (int i = 1; i < answer.length; i++) {
            System.out.println(answer[i]);
        }

    }

    static void DFS(int now) {

        // 현재 방문한 노드 출력
        // System.out.println(now);
        answer[now] = cnt;
        // 방문체크
        visited[now] = 1;

        // 다음 node 찾기
        for (int node : graph.get(now)) {
            // 방문하지 않았으면
            if (visited[node] == 0) {
                cnt++;
                //방문하기
                DFS(node);
            }
        }
    }

    // 1 3 4 2
    // 1 4 2 3
}

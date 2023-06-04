import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * [BOJ] 1012 / 유기농 배추 / 실버2
 */
public class BOJ_1012 {

    // 배추밭의 가로 길이
    static int W;

    // 배추밭의 세로 길이
    static int H;

    // 배추가 심어져있는 위치의 개수
    static int K;

    static int[][] graph;

    static int[][] visited;


    // 상하좌우
    static int[] moveX = {0, 0, -1, 1};
    static int[] moveY = {-1, 1, 0, 0};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // 테스트 케이스 개수
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int answer = 0;
            st = new StringTokenizer(br.readLine());

            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            visited = new int[W][H];
            graph = new int[W][H];

            // 배추밭 그리기
            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());

                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                graph[x][y] = 1;
            }

            // 그래프 돌면서 영역 체크하고, answer 1추가하기
            for (int k = 0; k < W; k++) {
                for (int j = 0; j < H; j++) {
                    // 그래프에서 1 인 곳이고, 방문하지 않았으면 DFS 돌면서 영역 찾기
                    if (graph[k][j] == 1 && visited[k][j] == 0) {
                        DFS(k, j);
                        answer++;
                    }
                }
            }

            System.out.println(answer);
        }

    }

    static void DFS(int nowX, int nowY) {

        // 방문체크
        visited[nowX][nowY] = 1;

        // 다음 노드 찾기
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];

            // 그래프를 벗어나는 경우
            if (nextX < 0 || nextX >= W || nextY < 0 || nextY >= H) {
                continue;
            }

            // 방문하지 않은 곳이라면
            if (graph[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
                DFS(nextX, nextY);
            }
        }

    }
}

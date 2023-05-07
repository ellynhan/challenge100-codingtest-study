import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static boolean[][] visited;
    static int arr[][];
    static int move_X[] = {-1, 1, 0, 0};
    static int move_Y[] = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine()), N, M, K;
        StringTokenizer st;
        int cnt = 0;

        for(int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            arr = new int[N + 2][M + 2];
            visited = new boolean[N + 2][M + 2];

            for(int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());
                arr[Integer.parseInt(st.nextToken()) + 1][Integer.parseInt(st.nextToken()) + 1] = 1;
            }

            for(int j = 1; j < arr.length; j++) {
                for(int k = 1; k < arr[j].length; k++) {
                    if(arr[j][k] == 1 && !visited[j][k]) {
                        search(j, k);
                        cnt++;
                    }
                }
            }

            System.out.println(cnt);
            cnt = 0;
        }

    }

    public static void search(int x, int y) {
        int t, w;
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            t = x + move_X[i];
            w = y + move_Y[i];

            if(arr[t][w] == 1 && !visited[t][w])
                search(t, w);
        }
    }

}
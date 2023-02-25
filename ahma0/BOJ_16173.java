import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class BOJ_16173 {

    static int n;
    static int arr[][];
    static boolean v[][];
    static int xarr[] = {0, 1}, yarr[] = {1, 0}; // x쪽으로 이동, y쪽으로 이동

    public static void main(String args[]) throws IOException {

        /**
         * 1 1
         * 1 5
         *
         * 오른쪽, 아래만 가능!
         * 1 1 10
         * 1 5 1
         * 2 2 -1
         *
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        v = new boolean[n][n];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        jeli(0, 0);

        System.out.println("Hing");


    }

    private static void jeli(int i, int j) {
        if (arr[i][j] == -1) {
            System.out.println("HaruHaru");
            System.exit(0);
        }

        for(int u = 0; u < 2; u++) {
            int x = i + xarr[u] * arr[i][j];
            int y = j + yarr[u] * arr[i][j];
            if(x >= n || y >= n || v[x][y]) continue;

            v[i][j] = true;
            jeli(x, y);
        }
    }
}

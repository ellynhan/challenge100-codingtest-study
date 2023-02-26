import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, M, R;
    static int[][] board;
    static int[][] res;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<R; i++) {
            int k = Integer.parseInt(st.nextToken());
            if(k == 1) updown();
            else if(k == 2) leftright();
            else if(k == 3) cw();
            else if(k == 4) ccw();
            else if(k == 5) split_cw();
            else split_ccw();
            board = res;
        }

        StringBuilder answer = new StringBuilder();
        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[0].length; j++) {
                answer.append(board[i][j]).append(' ');
            }
            answer.append('\n');
        }
        System.out.println(answer);
    }

    private static void split_ccw() {
        int n = board.length, m = board[0].length;
        res = new int[n][m];
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<m/2; j++) {
                res[i+n/2][j] = board[i][j];
            }
        }
        for(int i=0; i<n/2; i++) {
            for(int j=m/2; j<m; j++) {
                res[i][j-m/2] = board[i][j];
            }
        }
        for(int i=n/2; i<n; i++) {
            for(int j=m/2; j<m; j++) {
                res[i-n/2][j] = board[i][j];
            }
        }
        for(int i=n/2; i<n; i++) {
            for(int j=0; j<m/2; j++) {
                res[i][j+m/2] = board[i][j];
            }
        }
    }

    private static void split_cw() {
        int n = board.length, m = board[0].length;
        res = new int[n][m];
        for(int i=0; i<n/2; i++) {
            for(int j=0; j<m/2; j++) {
                res[i][j+m/2] = board[i][j];
            }
        }
        for(int i=0; i<n/2; i++) {
            for(int j=m/2; j<m; j++) {
                res[i+n/2][j] = board[i][j];
            }
        }
        for(int i=n/2; i<n; i++) {
            for(int j=m/2; j<m; j++) {
                res[i][j-m/2] = board[i][j];
            }
        }
        for(int i=n/2; i<n; i++) {
            for(int j=0; j<m/2; j++) {
                res[i-n/2][j] = board[i][j];
            }
        }
    }

    private static void ccw() {
        int n = board.length, m = board[0].length;
        res = new int[m][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res[m-j-1][i] = board[i][j];
            }
        }
    }

    private static void cw() {
        int n = board.length, m = board[0].length;
        res = new int[m][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res[j][n-i-1] = board[i][j];
            }
        }
    }

    private static void leftright() {
        int n = board.length, m = board[0].length;
        res = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res[i][m-j-1] = board[i][j];
            }
        }
    }

    private static void updown() {
        int n = board.length, m = board[0].length;
        res = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res[n-i-1][j] = board[i][j];
            }
        }
    }
}

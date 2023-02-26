import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M, R;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        arr = new int[N][M];
        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        List<int[]> from, to;
        for(int r=0; r<R; r++) {
            for(int k=0; k<Math.min(N, M)/2; k++) {
                from = flatten(k, k);
                to = flatten(k, k);
                to.add(to.remove(0));
                rotate(from, to);
            }
        }

        StringBuilder answer = new StringBuilder();
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                answer.append(arr[i][j] + " ");
            }
            answer.append("\n");
        }
        System.out.println(answer);
    }

    private static void rotate(List<int[]> from, List<int[]> to) {
        int tmp = arr[to.get(to.size()-1)[0]][to.get(to.size()-1)[1]];
        for(int i=from.size()-1; i>0; i--) {
            int fx = from.get(i)[0], fy = from.get(i)[1];
            int tx = to.get(i)[0], ty = to.get(i)[1];

            arr[tx][ty] = arr[fx][fy];
        }
        arr[to.get(0)[0]][to.get(0)[1]] = tmp;
    }

    private static List<int[]> flatten(int x, int y) {
        List<int[]> res = new ArrayList<>();
        int i = x, j = y;

        // +x
        for(; i<N-x; i++) res.add(new int[] {i, j});
        i--;
        j++;

        // +y
        for(; j<M-y; j++) res.add(new int[] {i, j});
        j--;
        i--;

        // -x
        for(; i>=x; i--) res.add(new int[] {i, j});
        i++;
        j--;

        // -y
        for(; j>y; j--) res.add(new int[] {i, j});

        return res;
    }

}

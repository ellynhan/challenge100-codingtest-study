import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_15650 {
    public static int N, M;
    public static int arr[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];

        fun(1, 0);

    }

    public static void fun(int at, int depth) {
        if(depth == M) {
            for(int i=0;i<M;i++) {
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            return;
        }

        for(int i = at; i <= N; i++) {
            arr[depth] = i;
            fun(i + 1, depth + 1);
        }
    }

}
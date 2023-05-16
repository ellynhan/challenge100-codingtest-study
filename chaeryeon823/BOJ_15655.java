import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_15655 {
    public static int N, M;
    public static int arr[];
    public static int num[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st=new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];
        num = new int[N];

        st=new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) {
            num[i]=Integer.parseInt(st.nextToken());
        }

        Arrays.sort(num);

        fun2(1, 0);

    }

    public static void fun2(int at, int depth) {
        if(depth == M) {
            for(int i=0;i<M;i++) {
                System.out.print(num[arr[i]-1]+" ");
            }
            System.out.println();
            return;
        }

        for(int i = at; i <= N; i++) {
            arr[depth] = i;
            fun2(i + 1, depth + 1);
        }
    }

}
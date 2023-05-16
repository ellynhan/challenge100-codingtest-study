import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_15649 {
    public static int N, M;
    public static int arr[];
    //    public static int num[];
    public static int ck[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st=new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];
        ck=new int[N];
//        num = new int[N];
//
//        st=new StringTokenizer(br.readLine());
//        for(int i=0;i<N;i++) {
//            num[i]=Integer.parseInt(st.nextToken());
//        }

//        Arrays.sort(num);

        fun3(0);

    }

    public static void fun3(int depth) {
        if(depth == M) {
            for(int i=0;i<M;i++) {
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            return;
        }

        for(int i = 1; i <= N; i++) {
            if(ck[i-1]==1) {
                continue;
            }
            arr[depth] = i;
            ck[i-1]=1;
            fun3(depth + 1);
            ck[i-1]=0;
        }
    }

}
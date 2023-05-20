import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N, M;
        int answer = 0;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        char[][] arr=new char[N][M];

        for(int i=0;i<N;i++) {
            String tmp=br.readLine();
            for(int j=0;j<M;j++) {
                arr[i][j]=tmp.charAt(j);
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                System.out.println(arr[i][j]);
            }
        }



    }
}

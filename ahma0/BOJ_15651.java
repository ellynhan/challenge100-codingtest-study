import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int N, M;
    public static int arr[];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M];

        dfs(0);

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

    public static void dfs(int depth) {
        if(depth == M) {
            for(int val : arr)
                sb.append(val).append(" ");
            sb.append("\n");
            return;
        }

        for(int i = 1; i <= N; i++) {
            arr[depth] = i;
            dfs(depth + 1);
        }
    }

}
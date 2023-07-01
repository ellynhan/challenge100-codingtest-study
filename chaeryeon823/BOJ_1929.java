import java.io.*;
import java.util.StringTokenizer;

/**
 * [BOJ] 1929 / 소수 구하기 / 실버3
 */
public class BOJ_1929 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        boolean arr[] = new boolean[n + 1];
        arr[0] = true;
        arr[1] = true;

        int sqrt = (int) Math.sqrt(n + 1);
        for (int i = 2; i <= sqrt; i++) {
            for (int j = i * i; j < n + 1; j += i) {
                arr[j] = true;
            }
        }

        for (int i = m; i < n + 1; i++) {
            if (!arr[i]) {
                bw.write(i + "\n");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

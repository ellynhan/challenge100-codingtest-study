import java.io.*;
import java.util.Arrays;

/**
 * [BOJ] 2485 / 가로수 / 실버4
 */
public class BOJ_2485 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        int[] list = new int[N];
        int[] distance = new int[N - 1];

        for (int i = 0; i < N; i++) {
            list[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(list);
        int gcd = 0;

        // 각 나무들 사이의 간격과 간격 최대공약수 구하기
        for (int i = 0; i < N - 1; i++) {
            distance[i] = list[i + 1] - list[i];
            gcd = GCD(distance[i], gcd);
        }

        //전체 가로수의 수
        int result = 0;
        result = (list[N-1]-list[0]) / gcd + 1;
        bw.write(String.valueOf(result - N));

        bw.flush();
        bw.close();
        br.close();

    }

    private static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return GCD(b, a % b);

    }
}

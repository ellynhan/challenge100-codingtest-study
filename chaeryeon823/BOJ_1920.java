import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1920 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] nArr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nArr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nArr);

        int M = Integer.parseInt(br.readLine());
        int[] mArr = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            mArr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < M; i++) {
            System.out.println(binarySearch(nArr, mArr[i]));
        }


    }

    public static int binarySearch(int[] arr, int num) {
        int b = 0;
        int t = arr.length - 1;
        int m = 0;
        while (b <= t) {
            m = (b + t) / 2;
            if (num < arr[m]) {
                t = m - 1;

            } else if (num > arr[m]) {
                b = m + 1;

            } else if (num == arr[m]) {
                return 1;

            }
        }
        return 0;
    }
}

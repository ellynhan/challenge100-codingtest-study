import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_2805 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n, target;
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        target = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int b = 1;
        int t = arr[n - 1];
        int mid = 0;
        while (b <= t) {
            mid = (b + t) / 2;
            double tmp = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] >= mid) {
                    tmp += (arr[i] - mid);
                }
            }
            if (tmp >= target) {
                b = mid + 1;
            } else {
                t = mid - 1;
            }
        }
        System.out.println(t);

    }
}

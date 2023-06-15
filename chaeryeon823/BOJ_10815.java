import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * [BOJ] 10815 / 숫자카드 / 실버5
 */
public class BOJ_10815 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        //상근이가 가지고 있는 숫자카드
        int N = Integer.parseInt(br.readLine());
        int[] arrN = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arrN[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arrN);

        //상근이가 가지고 있는지 확인하는 숫자배열
        int M = Integer.parseInt(br.readLine());
        int[] arrM = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            arrM[i] = Integer.parseInt(st.nextToken());
        }

        //이분탐색으로 찾고 출력하기
        for(int i=0;i<M;i++) {
            System.out.print(binarySearch(arrN, arrM[i])+" ");
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

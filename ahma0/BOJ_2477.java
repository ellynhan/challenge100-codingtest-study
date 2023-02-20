import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2477 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        int arr[][] = new int[2][6];
        int[] max = new int[2], index = new int[2], left = new int[2], right = new int[2];

        for(int i = 0; i < 6; i++) {
            st = new StringTokenizer(br.readLine());

            arr[0][i] = Integer.parseInt(st.nextToken());
            arr[1][i] = Integer.parseInt(st.nextToken());

        }

        for(int i = 0; i < 6; i++) {

            if(arr[0][i] <= 2 && max[0] < arr[1][i]) {
                max[0] = arr[1][i];
                index[0] = i;
            }
            if(arr[0][i] >= 3 && max[1] < arr[1][i]) {
                max[1] = arr[1][i];
                index[1] = i;
            }
        }

        if(arr[0][index[0]] <= 2) {
            if(index[0] == 0) {
                left[0] = arr[1][5];
                right[0] = arr[1][index[0] + 1];
            }
            else if(index[0] == 5) {
                right[0] = arr[1][0];
                left[0] = arr[1][index[0] - 1];
            }
            else {
                left[0] = arr[1][index[0] - 1];
                right[0] = arr[1][index[0] + 1];
            }
        }
        if(arr[0][index[1]] >= 3) {
            if(index[1] == 0) {
                left[1] = arr[1][5];
                right[1] = arr[1][index[1] + 1];
            }
            else if(index[1] == 5) {
                right[1] = arr[1][0];
                left[1] = arr[1][index[1] - 1];
            }
            else {
                left[1] = arr[1][index[1] - 1];
                right[1] = arr[1][index[1] + 1];
            }
        }

        System.out.println((max[0] * max[1] - (Math.abs(right[0] - left[0]) * Math.abs(right[1] - left[1]))) * N);

    }

}
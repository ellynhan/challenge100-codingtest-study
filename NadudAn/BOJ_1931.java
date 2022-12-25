import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class BOJ_1931 {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine()), b = 0, cnt = 0;

        int arr[][] = new int[n][2];

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < 2; j++)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1]==o2[1]) {
                    return o1[0]-o2[0];
                }
                return o1[1]-o2[1];
            }
        });

        for(int i = 0; i < n; i++) {
            if(arr[i][0] >= b) {
                b = arr[i][1];
                cnt++;
            }

        }

        System.out.println(cnt);

    }
}

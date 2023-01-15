import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class BOJ_2566 {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int arr[][] = new int[9][9];
        int max = 0, c = 0, r = 0;

        for(int i = 0; i < 9; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < 9; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());

                if(max < arr[i][j]) {
                    max = arr[i][j];
                    r = i + 1;
                    c = j + 1;
                }
            }
        }

        if (max == 0) {
            r = 1;
            c = 1;
        }

        System.out.println(max);
        System.out.println(r + " " + c);

    }
}

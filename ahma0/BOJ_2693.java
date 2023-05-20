import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;

        Integer arr[] = new Integer[10];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < arr.length; j++)
                arr[j] = Integer.parseInt(st.nextToken());

            Arrays.sort(arr, Collections.reverseOrder());

            System.out.println(arr[2]);

        }

        br.close();
    }

}
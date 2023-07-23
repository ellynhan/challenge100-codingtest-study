import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int arr[] = new int[6];

        for(int i = 0; i < t; i++) {
            st = new StringTokenizer(br.readLine(), " ");

            for(int j = 0; j < 6; j++)
                arr[j] = Integer.parseInt(st.nextToken());

            System.out.println(circle(arr));
        }

    }

    public static int circle(int arr[]) {
        int points = (int) (Math.pow(arr[3] - arr[0], 2) + Math.pow(arr[4] - arr[1], 2));

        if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == arr[4] && arr[4] == arr[5])
            return 1;

        if(arr[0] == arr[3] && arr[1] == arr[4] && arr[2] == arr[5])
            return -1;
        else if(points > Math.pow(arr[2] + arr[5], 2))
            return 0;
        else if(points < Math.pow(arr[5] - arr[2], 2))
            return 0;
        else if(points == Math.pow(arr[2] + arr[5], 2))
            return 1;
        else if(points == Math.pow(arr[5] - arr[2], 2))
            return 1;
        else return 2;
    }

}
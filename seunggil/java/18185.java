import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());
        int[] inputData = new int[n];
        StringTokenizer token = new StringTokenizer(re.readLine());
        for (int i = 0; i < n; i++) {
            inputData[i] = Integer.parseInt(token.nextToken());
        }

        long ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (inputData[i + 1] > inputData[i + 2]) {
                int diff = inputData[i + 1] - inputData[i + 2];
                diff = Integer.min(inputData[i], diff);

                inputData[i] -= diff;
                inputData[i + 1] -= diff;

                ans += 5 * diff;
                if (inputData[i] != 0)
                    i--;
            } else {
                int diff = Integer.min(inputData[i], inputData[i + 1]);

                inputData[i] -= diff;
                inputData[i + 1] -= diff;
                inputData[i + 2] -= diff;

                ans += 7 * diff;
                ans += 3 * inputData[i];
                inputData[i] = 0;
            }

        }
        int large, small;
        if (inputData[n - 2] < inputData[n - 1]) {
            large = inputData[n - 1];
            small = inputData[n - 2];
        } else {
            large = inputData[n - 2];
            small = inputData[n - 1];
        }
        ans += 5 * small;
        ans += 3 * (large - small);

        System.out.print(ans);
        re.close();
    }
}
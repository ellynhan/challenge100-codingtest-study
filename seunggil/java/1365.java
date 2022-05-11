import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[] dp;

    static int binarySearch(int len, int target){
        int start = 0;
        int end = len - 1;

        while(start <= end){
            int mid = (start + end) / 2;
            if(dp[mid] == target){
                return mid;
            }else if(dp[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        dp[start] = target;
        return start;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());
        dp = new int[n];

        int ans = 1;
        StringTokenizer token = new StringTokenizer(re.readLine());
        dp[0] = Integer.parseInt(token.nextToken());
        for(int i = 1; i < n; i++){
            ans = Integer.max(ans, binarySearch(ans, Integer.parseInt(token.nextToken())) + 1);
        }
        System.out.print(n - ans);

        re.close();
    }
}

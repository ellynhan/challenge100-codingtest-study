import java.util.*;
import java.io.*;

public class Main2 {
    static final int p = 1_000_000_007;
    static int power(long a, long b){
        long result = 1;

        while(b > 0){
            if(b % 2 == 1){
                result *= a;
                result %= p;
            }
            b >>= 1;
            a = (a * a) % p;
        }
        return (int)result;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer token = new StringTokenizer(re.readLine());

        int n = Integer.parseInt(token.nextToken());
        int k = Integer.parseInt(token.nextToken());

        long[] dp = new long[n+1];
        dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            dp[i] = (dp[i-1]*i) % p;
        }
        long result = ((dp[n] * power(dp[k], p-2)) % p) * power(dp[n-k], p - 2);
        System.out.println(result % p);    
        re.close();
    }
}

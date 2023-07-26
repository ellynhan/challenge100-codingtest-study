import java.util.*;
import java.io.*;

public class BOJ_BinarySearch_G5_2467 {
    public static void main(String[] args) throws IOException {
        final int INF = 1000000000;
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(re.readLine());
        
        TreeSet<Integer> tree = new TreeSet<>();

        StringTokenizer token = new StringTokenizer(re.readLine());
        int[] inputData = new int[n];
        int idx = 0;

        for(;idx < n; idx++){
            inputData[idx] = Integer.parseInt(token.nextToken());
            tree.add(inputData[idx]);

            if(inputData[idx] > 0){
                tree.pollLast();
                break;
            }
        }
        // 양수
        for(int i = idx + 1; i < n; i++){
            inputData[i] = Integer.parseInt(token.nextToken());
        }

        int[] ans = new int[]{Integer.MAX_VALUE, INF, INF};
        for(int i = idx; i < n; i++){
            Integer ceiling = tree.ceiling(-inputData[i]);
            Integer floor = tree.floor(-inputData[i]);

            if(ceiling != null){
                int property = Math.abs(ceiling + inputData[i]);
                if(ans[0] > property){
                    ans[0] = property;
                    ans[1] = ceiling;
                    ans[2] = inputData[i];
                }
            }
            if(floor != null){
                int property = Math.abs(floor + inputData[i]);
                if(ans[0] > property){
                    ans[0] = property;
                    ans[1] = floor;
                    ans[2] = inputData[i];
                }
            }
        }

        int[] minus = new int[]{-INF, -INF};
        // 음수 2개 섞는 경우;
        for(int i = idx -1; i >= idx -2 && i>= 0; i--){
            minus[i - (idx -2)] = inputData[i];
        }

        int property = Math.abs(minus[0] + minus[1]);
        if(ans[0] > property){
            ans[0] = property;
            ans[1] = minus[0];
            ans[2] = minus[1];
        }

        int[] plus = new int[]{INF, INF};
        // 양수 2개 섞는 경우;
        for(int i = idx; i <= idx+1 && i < n; i++){
            plus[i - (idx)] = inputData[i];
        }

        property = Math.abs(plus[0] + plus[1]);
        if(ans[0] > property){
            ans[0] = property;
            ans[1] = plus[0];
            ans[2] = plus[1];
        }

        StringBuilder result = new StringBuilder();
        result.append(ans[1]).append(' ').append(ans[2]);

        System.out.print(result);

        re.close();
    }
}

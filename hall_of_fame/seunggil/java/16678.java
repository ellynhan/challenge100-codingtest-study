import java.util.*;
import java.io.*;

public class _BOJ_Greedy_G5_16678 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(re.readLine());
        
        int[] inputData = new int[n];
        for(int i = 0; i < n; i++){
            inputData[i] = Integer.parseInt(re.readLine());
        }
        
        Arrays.sort(inputData);

        long answer = 0;
        int num = 1;
        for(int iter : inputData){
            if(num <= iter){
                answer += iter - num;
                num++;
            }
        }

        System.out.print(answer);
        re.close();
    }
}
 
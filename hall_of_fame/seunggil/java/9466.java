import java.util.*;
import java.io.*;

class Person{
    int counter = 0;
    int next = 0;
}
public class BOJ_TPsort_G3_9466 {
    static Person[] inputData = new Person[100_001];

    static void dfs(int now){
        if(--(inputData[now].counter) == 0){
            inputData[now].counter = -1;
            dfs(inputData[now].next);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(re.readLine());
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < 100_001; i++){
            inputData[i] = new Person();
        }
        for(int t = 0; t < testCase; t++){
            int n = Integer.parseInt(re.readLine());
            for(int i = 1; i <= n; i++){
                inputData[i].counter = 0;
                inputData[i].next = -1;
            }
            StringTokenizer token = new StringTokenizer(re.readLine());
            for(int i = 1; i <= n; i++){
                int to = Integer.parseInt(token.nextToken());
                inputData[i].next = to;
                inputData[to].counter++;
            }

            for(int i = 1; i <= n; i++){
                if(inputData[i].counter == 0){
                    inputData[i].counter--;
                    dfs(inputData[i].next);
                }
            }

            int result = 0;
            for(int i = 1; i <= n; i++){
                if(inputData[i].counter == -1)
                    result++;
            }
            ans.append(result).append('\n');
        }
        System.out.print(ans);
        re.close();
    }
}

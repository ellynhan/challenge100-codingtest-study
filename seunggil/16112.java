import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());

        int questCnt = Integer.parseInt(token.nextToken());
        int maxCnt = Integer.parseInt(token.nextToken());
        int[] inputData = new int[questCnt];

        token = new StringTokenizer(re.readLine());
        for(int i = 0; i < questCnt; i++){
            inputData[i] = Integer.parseInt(token.nextToken());
        }

        Arrays.sort(inputData);

        long answer = 0;
        int nowCnt = 0;

        for(int iter : inputData){
            answer += (1L * iter * nowCnt);
            if(nowCnt < maxCnt)
                nowCnt++;
        }

        System.out.print(answer);
        re.close();
    }
}
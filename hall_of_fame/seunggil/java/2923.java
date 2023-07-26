import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class _BOJ_Greedy_P5_2923{
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        int[] setA = new int[101];
        int[] setB = new int[101];
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < n; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());

            setA[Integer.parseInt(token.nextToken())]++;
            setB[Integer.parseInt(token.nextToken())]++;

            int aCnt = 0;
            int bCnt = 0;


            int aIdx = 0;
            int bIdx = 101;

            int value = 0;
            while(true){
                if(aCnt == 0){
                    ++aIdx;
                    while(aIdx <= 100 && setA[aIdx] == 0)
                        ++aIdx;
                }
                if(bCnt == 0){
                    --bIdx;
                    while(bIdx >= 1 && setB[bIdx] == 0)
                        --bIdx;
                }
                
                if(aIdx > 100 || bIdx < 1)
                    break;

                if(aCnt == 0){
                    aCnt = setA[aIdx];
                }
                if(bCnt == 0){
                    bCnt = setB[bIdx];
                }
                
                value = Integer.max(value, aIdx + bIdx);

                if(aCnt > bCnt){
                    aCnt -= bCnt;
                    bCnt = 0;
                }else{
                    bCnt -= aCnt;
                    aCnt = 0;
                }
            }
            
            ans.append(value).append('\n');
        }

        System.out.println(ans);
        re.close();
    }
}
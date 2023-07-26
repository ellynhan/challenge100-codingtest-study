import java.util.*;
import java.io.*;

public class Main{
   public static void main(String[] args) throws IOException {
      BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
      int testCase = Integer.parseInt(re.readLine());
      StringBuilder ans = new StringBuilder();

      int[][] inputData = new int[500][500];
      final int INF = 5000000;
      
      start : for(int t = 0; t < testCase; t++){
         StringTokenizer token = new StringTokenizer(re.readLine());
         int nodeCnt = Integer.parseInt(token.nextToken());
         int edgeCnt = Integer.parseInt(token.nextToken());
         int portalCnt = Integer.parseInt(token.nextToken());
         
         for(int i = 0; i < nodeCnt; i++){
            for(int j = 0; j < nodeCnt; j++){
               if(i == j)
                  inputData[i][j] = 0;
               else
                  inputData[i][j] = INF;
            }
         }

         for(int i = 0; i < edgeCnt; i++){
            token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken()) -1;
            int b = Integer.parseInt(token.nextToken()) -1;
            int v = Integer.parseInt(token.nextToken());
            inputData[a][b] = Math.min(inputData[a][b], v);
            inputData[b][a] = inputData[a][b];
         }

         for(int i = 0; i < portalCnt; i++){
            token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken())-1;
            int b = Integer.parseInt(token.nextToken())-1;
            int v = Integer.parseInt(token.nextToken());
            inputData[a][b] = Math.min(inputData[a][b], -v);
         }

          for(int i = 0; i < nodeCnt; i++){
            for(int j = 0; j < nodeCnt; j++){
               for(int k = 0; k < nodeCnt; k++){
                  inputData[j][k] = Math.min(inputData[j][i]+inputData[i][k], inputData[j][k]);
                  if(j == k && inputData[j][k] < 0){
                     ans.append("YES\n");
                     continue start;
                  }
               }
            }
         }
         
         ans.append("NO\n");

      }

      System.out.print(ans);
      re.close();
   }
}
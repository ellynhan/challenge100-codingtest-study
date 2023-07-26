import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class Main{
   static int countOne(int n){
      int result = 0;
      while(n != 0){
         n &= n-1;
         result++;
      }
      return result;
   }
   public static void main(String[] args) throws IOException {
      final int[] legType = new int[]{3,5,6,9,10,12,17,18,20,24};
      final int INF = 500_000;

      BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
      
      String s = re.readLine();
      List<Integer> inputData = new ArrayList<>(s.length()/2);
      StringTokenizer token = new StringTokenizer(s);

      
      while(token.hasMoreTokens()){
         int dir = Integer.parseInt(token.nextToken());
         if(dir == 0)
            continue;
         inputData.add(dir);
      }

      Map<Integer,Integer[]> dp = new HashMap<>();
      for(int i = 0; i < 10; i++){
         dp.put(legType[i], new Integer[100_001]);
         Arrays.fill(dp.get(legType[i]), INF);
      }

      dp.get(Integer.valueOf((1 << inputData.get(0)) + 1))[0] = 2;

      for(int i = 1, n = inputData.size(); i < n; i++){
         int dir = inputData.get(i);
         for (Entry<Integer, Integer[]> dpIter : dp.entrySet()) {
            // 1 => 00010
            // 2 => 00100
            // 3 => 01000
            // 4 => 10000
            Integer nowLoc = dpIter.getKey();
            Integer[] nowLocDp = dpIter.getValue();
            // xor 연산 결과 1의 갯수가 1개면 => 기존에 있는 곳 또 밟기.
            if(countOne(nowLoc ^ (1 << dir)) == 1){
               nowLocDp[i] = Math.min(nowLocDp[i], nowLocDp[i-1] + 1);
            }else{
               // 중심에 있는 다리가 있으면,
               if((nowLoc.intValue() & 1) != 0){
                  int nextLoc = (nowLoc.intValue() - 1) | (1 << dir);
                  dp.get(nextLoc)[i] = Math.min(dp.get(nextLoc)[i], nowLocDp[i-1] + 2);
               }
               if((nowLoc & ~(1)) == 0)
                  continue;
               for(int j = 1; j < 5; j++){
                  if(((1 << j) & nowLoc.intValue()) != 0){
                     int nextLoc = (nowLoc.intValue() & ~(1 << j)) | (1 << dir);
                     Integer[] nextLocDp = dp.get(nextLoc);
                     if(Math.abs(dir - j) == 2){
                        nextLocDp[i] = Math.min(nextLocDp[i], nowLocDp[i-1] + 4);
                     }else{
                        nextLocDp[i] = Math.min(nextLocDp[i], nowLocDp[i-1] + 3);
                     }
                  }
               }
            }
            
         }
      }

      int ans = INF;
      for (Entry<Integer, Integer[]> dpIter : dp.entrySet()){
         ans = Math.min(ans, dpIter.getValue()[inputData.size()-1]);
      }

      System.out.print(ans);

      re.close();
   }
}
import java.util.*;
import java.io.*;

public class Main{
   public static void main(String[] args) throws IOException {
      BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
      
      char[] inputData = re.readLine().toCharArray();
      Map<Integer, Integer> map = new HashMap<>();

      int dp = 0;

      // s나 k가 한번이라도 나왔는지 여부.
      boolean start = false;

      int ans = 0;
      for(int i = 0, n = inputData.length; i < n; i++){
         if(inputData[i] == 'S'){
            dp += 2;
            start = true;

         }else if(inputData[i] == 'K'){
            dp += -1;
            start = true;
         }

         if(dp == 0){
            if(start){
               ans = Math.max(ans, i+1);
            }
         }else{
            if(map.containsKey(dp)){
               int s = map.get(dp);
               if(i-s > ans){
                  for(int j = s+1; j <= i; j++){
                     if(inputData[j] == 'S' || inputData[j] == 'K'){
                        ans = i-s;
                        break;
                     }
                  }
               }
            }else{
               map.put(dp, i);
            }
         }
      }
      if(ans == 0)
         System.out.print(-1);
      else
         System.out.print(ans);
      re.close();
   }
}
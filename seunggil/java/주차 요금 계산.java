import java.util.*;
import java.util.Map.*;
import java.io.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        final int ENDTIME = 1439;
        int defaultTime = fees[0];
        int defaultMoney = fees[1];
        int unitTime = fees[2];
        int unitMoney = fees[3];
        
        Map<Integer,Integer> totalFee = new TreeMap<>();
        Map<Integer,Integer> park = new HashMap();
        
        for(String record : records){
            StringTokenizer token = new StringTokenizer(record);
            String[] time = token.nextToken().split(":");
            int number = Integer.parseInt(token.nextToken());
            boolean isIn = token.nextToken().equals("IN") ? true : false;
            
            if(isIn){
                park.put(number, Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]));
            }else{
                totalFee.put(number, totalFee.getOrDefault(number, 0)
                             + Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]) - park.get(number));
                park.put(number, ENDTIME);
            }
        }
        
        for(Entry<Integer, Integer> iter : park.entrySet()){
            int number = iter.getKey();
            totalFee.put(number, totalFee.getOrDefault(number, 0)
                             + ENDTIME - park.get(number));
        }
        
        int[] answer = new int[totalFee.size()];
        int idx = 0;
        for(Entry<Integer, Integer> iter : totalFee.entrySet()){
            if(iter.getValue() <= defaultTime){
                answer[idx] = defaultMoney;
            }else{
                answer[idx] = defaultMoney + 
                    (int)(Math.ceil((iter.getValue() - defaultTime)/ (double)unitTime) * unitMoney);
            }
            
            idx++;
        }
        
        return answer;
    }
}
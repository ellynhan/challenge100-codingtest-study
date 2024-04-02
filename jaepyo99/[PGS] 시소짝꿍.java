// 정렬을 하였다는게 중요한 포인트
import java.util.*;
class Solution {
    Map<Integer,Integer>map=new HashMap<>();
    public long solution(int[] weights) {
        long answer=0;
        Arrays.sort(weights);
        Map<Double,Integer>map=new HashMap<>();
        for(int weight:weights){
            double a=(weight*1.0)/1.0;
            double b=(weight*2.0)/3.0;
            double c=(weight*2.0)/4.0;
            double d=(weight*3.0)/4.0;
            if(map.containsKey(a)){
                answer+=map.get(a);
            }
            if(map.containsKey(b)){
                answer+=map.get(b);
            }
            if(map.containsKey(c)){
                answer+=map.get(c);
            }
            if(map.containsKey(d)){
                answer+=map.get(d);
            }
            map.put(a,map.getOrDefault(a,0)+1);
        }
        return answer;
    }
}

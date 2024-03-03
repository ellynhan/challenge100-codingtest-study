import java.util.*;
class Solution {
    public int solution(int k, int[] tangerines) {
        int answer = 0;
        Map<Integer,Integer>map=new HashMap<>();
        
        for(int tangerine:tangerines){
            map.put(tangerine,map.getOrDefault(tangerine,0)+1);
        }
        
        List<Integer>list=new ArrayList<>(map.values());
        Collections.sort(list,Collections.reverseOrder());
        
        int cnt=0;
        for(Integer l:list){
            if(k>0){
                k=k-l;
                cnt++;
            }else{
                break;
            }
        }
        
        return cnt;
    }
}

import java.util.*;
class Solution {
    Map<String,Integer>map=new HashMap<>();
    public String sortString(String str){
        char[] charArr = str.toCharArray();
        Arrays.sort(charArr);
        String result = new String(charArr);
        return result;
    }
    public void dfs(String order,int c,int startIdx,String str){
        if(str.length()==c){
            map.put(str,map.getOrDefault(str,0)+1);
            return;
        }
        for(int i=startIdx;i<order.length();i++){
            str+=order.charAt(i);
            dfs(order,c,i+1,str);
            str=str.substring(0,str.length()-1);
        }
        return;
    }
    public String[] solution(String[] orders, int[] course) {
        for(int i=0;i<orders.length;i++){
            orders[i]=sortString(orders[i]);
        }
        for(int c:course){
            for(int i=0;i<orders.length;i++){
                dfs(orders[i],c,0,"");
            }
        }
        int[]ca=new int[course.length];
        int n=0;
        
        for(int c:course){
            int max_num=-1;
            for(String key:map.keySet()){
                if(key.length()==c){
                    if(max_num<map.get(key)){
                        max_num=map.get(key);
                    }
                }
            }    
            ca[n++]=max_num;
        }
        
        List<String>arr=new ArrayList<>();
        
        for(int i=0;i<course.length;i++){
            int c_max=ca[i];
            for(String key:map.keySet()){
                if(key.length()==course[i] ){
                    if(c_max==map.get(key) && map.get(key)>=2){
                        arr.add(key);
                    }
                }
            }    
        }
        String[] answer=arr.toArray(new String[arr.size()]);
        Arrays.sort(answer);
        return answer;
    }
}

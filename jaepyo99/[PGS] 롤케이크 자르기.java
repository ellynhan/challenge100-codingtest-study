import java.util.*;
class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        int[] arr1=new int[topping.length+1];
        int[] arr2=new int[topping.length+1];
        Map<String,String>map=new HashMap<>();
        int num=0;
        arr1[0]=0;
        arr2[topping.length]=0;
        for(int i=1;i<=topping.length;i++){
            if(map.get(String.valueOf(topping[i-1]))!=null){
                arr1[i]=num;
            }else{
                map.put(String.valueOf(topping[i-1]),"true");
                num++;
                arr1[i]=num;
            }
        }
        
        map.clear();
        num=0;
        for(int i=topping.length-1;i>=0;i--){
            if(map.get(String.valueOf(topping[i]))!=null){
                
                arr2[i]=num;
            }else{
                map.put(String.valueOf(topping[i]),"true");
                num++;
                arr2[i]=num;
            }
        }
        
        for(int i=0;i<topping.length;i++){
            if(arr1[i]==arr2[i]){
                answer++;
            }
        }
        
        return answer;
    }
}

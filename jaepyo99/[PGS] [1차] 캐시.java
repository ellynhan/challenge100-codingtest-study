import java.util.*;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        LinkedList<String>list=new LinkedList<>();
        for(int i=0;i<cities.length;i++){
            cities[i]=cities[i].toUpperCase();
        }
        for(int i=0;i<cities.length;i++){
            if(list.size()<cacheSize){
                if(list.contains(cities[i])){
                    list.remove(list.indexOf(cities[i]));
                    list.addLast(cities[i]);
                    answer+=1;
                }else{
                    list.addLast(cities[i]);    
                    answer+=5;
                }
            }
            else{
                if(list.contains(cities[i])){
                    list.remove(list.indexOf(cities[i]));
                    list.addLast(cities[i]);
                    answer+=1;
                }else{
                    if(list.size()!=0){
                        list.removeFirst();
                        list.addLast(cities[i]);
                    }
                    answer+=5;
                }
            }
        }
        return answer;
    }
}

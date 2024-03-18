import java.util.*;
class Solution {
    public int solution(int[] orders) {
        int answer = 0;
        Stack<Integer>belt=new Stack<>();
        Stack<Integer>truck=new Stack<>();
        
        int j=1;
        for(int order:orders){
            if(belt.isEmpty()==false){
                if(belt.peek()==order){
                    truck.push(belt.pop());
                    continue;
                }
            }
            if(j>orders.length){
                break;
            }
            while(j<=orders.length){
                if(order==j){
                    truck.push(j);
                    j++;
                    break;
                }else{
                    belt.push(j);
                    j++;
                }
            }
        }
        
        return truck.size();
    }
}

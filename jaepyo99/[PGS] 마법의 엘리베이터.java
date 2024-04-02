class Solution {
    public int solution(int storey) {
        int answer = 0;
        while(storey>0){
            int back=storey%10;
            storey/=10;
            if(back>5){
                answer+=10-back;
                storey+=1;
            }else if(back<5){
                answer+=back;
            }else{
                if(storey%10>=5){
                    answer+=5;
                    storey+=1;
                }else{
                    answer+=back;
                }
            }
        }
        return answer;
    }
}

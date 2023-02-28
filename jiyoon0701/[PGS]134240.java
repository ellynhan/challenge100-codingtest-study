import java.lang.StringBuffer;

class Solution { 
    public StringBuffer solution(int[] food) {
        StringBuffer answer = new StringBuffer("");
        
        for(int i=1; i<food.length; i++){
            if(food[i] >= 2){
                for(int j=1; j<= food[i]/2; j++){
                    answer=answer.append(String.valueOf(i));
                }
            }
        }
        StringBuffer answerReverse = new StringBuffer(answer);
        answerReverse = answerReverse.reverse();
        answer.insert(answer.length(),"0");
        answer = answer.append(answerReverse);
        
        return answer;
    }
}

public class Solution {

    public String solution(int[] food) {
        String answer = "";

        for(int i = 1; i < food.length; i++)
            for(int j = 0; j < food[i] / 2; j++)
                answer += i;

        answer += 0 + reverse(answer);

        return answer;
    }

    public String reverse(String str) {
        return new StringBuilder(str).reverse().toString();
    }

}
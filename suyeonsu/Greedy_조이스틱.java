public class Solution {
    public static int solution(String name) {
        int answer = 0;
        int move = name.length()-1;
        for(int i=0; i<name.length(); i++) {
            answer += Math.min(name.charAt(i) - 'A', 26 - (name.charAt(i) - 'A'));
            if(i != name.length()-1 && name.charAt(i+1) == 'A') {
                int ei = i+1;
                while(ei < name.length() && name.charAt(ei) == 'A') ei++;
                move = Math.min(move, i*2 + name.length()-ei);  // 오른쪽으로 갔다 다시 왼쪽으로
                move = Math.min(move, i + (name.length()-ei)*2);    // 왼쪽으로 갔다 다시 오른쪽으로
            }
        }
        return answer + move;
    }
}

/*
탐욕적인 방법으로 문제를 해결할 때는 어느 부분의 값이 변동적인지(수행순서나 진행방향에따라 다른 값이 나오는부분이 어딘지) 주의깊게 생각해보자.
*/

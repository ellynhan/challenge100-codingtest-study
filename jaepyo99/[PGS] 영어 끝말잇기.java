import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        List<String> save = new ArrayList<>();
        int[] answer = new int[2];
        int turn = 0;
        int person = 0;

        for (int i = 0; i < words.length; i++) {
            if (i % n == 0) {
                turn++;
                person = 0;
            }
            person++;

            if (save.contains(words[i])) { 
                answer[0] = person;
                answer[1] = turn;
                return answer;
            } else if(i > 0 && words[i-1].charAt(words[i-1].length()-1) != words[i].charAt(0)){
                answer[0] = person;
                answer[1] = turn;
                return answer;
            } else {
                save.add(words[i]);
            }
        }

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        answer[0] = 0;
        answer[1] = 0;
        return answer;
    }
}

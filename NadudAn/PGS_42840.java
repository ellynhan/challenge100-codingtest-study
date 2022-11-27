import java.util.ArrayList;

class Solution {
    int[] std1 = { 1, 2, 3, 4, 5 }, std2 = { 2, 1, 2, 3, 2, 4, 2, 5 }, std3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    public int[] solution(int[] answers) {
        int[] cnt = { 0, 0, 0 };
        ArrayList<Integer> answer = new ArrayList<Integer>();

        for(int i = 0; i < answers.length; i++) {
            if(answers[i] == std1[i % 5]) cnt[0]++;
            if(answers[i] == std2[i % 8]) cnt[1]++;
            if(answers[i] == std3[i % 10]) cnt[2]++;
        }

        if(cnt[0] == cnt[1] && cnt[1] == cnt[2]) {
            answer.add(1);
            answer.add(2);
            answer.add(3);
        }
        else if(cnt[0] == cnt[1] && cnt[0] > cnt[2]){
            answer.add(1);
            answer.add(2);
        }
        else if(cnt[0] == cnt[2] && cnt[0] > cnt[1]){
            answer.add(1);
            answer.add(3);
        }
        else if(cnt[1] == cnt[2] && cnt[0] < cnt[1]){
            answer.add(2);
            answer.add(3);
        }
        else if(cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
            answer.add(1);
        }
        else if(cnt[1] > cnt[0] && cnt[1] > cnt[2]) {
            answer.add(2);
        }
        else if(cnt[2] > cnt[0] && cnt[2] > cnt[1]) {
            answer.add(3);
        }

        int[] arr = answer.stream().mapToInt(Integer::intValue).toArray();
        return arr;
    }
}

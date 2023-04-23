
public class Solution {

    String[] b = {"aya", "ye", "woo", "ma"};

    public int solution(String[] babbling) {
        int answer = 0;

        for(int i = 0; i < babbling.length; i++) {
            for(String t : b) {
                if(babbling[i].contains(t)) babbling[i] = babbling[i].replace(t, "1");
            }

            babbling[i] = babbling[i].replaceAll("1", "");

            if(babbling[i].equals("")) answer++;
        }

        return answer;
    }

}
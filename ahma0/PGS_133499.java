
public class Solution {

    public int solution(String[] babbling) {
        int answer = 0;

        String[] b = {"aya", "ye", "woo", "ma"};
        String[] b2 = {"ayaaya", "yeye", "woowoo", "mama"};

        for(int i = 0; i < babbling.length; i++) {
            for(int j = 0; j < b.length; j++) {
                if(babbling[i].contains(b2[j]))
                    babbling[i] = babbling[i].replace(b[j], "2");
                if(babbling[i].contains(b[j]))
                    babbling[i] = babbling[i].replace(b[j], "1");
            }
            babbling[i] = babbling[i].replaceAll("1", "");

            if(babbling[i].equals("")) answer += 1;
        }


        return answer;
    }

}
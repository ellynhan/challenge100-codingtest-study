import java.util.ArrayList;
import java.util.StringTokenizer;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringTokenizer st = new StringTokenizer(s);

        ArrayList<String> al = new ArrayList<>();

        while(st.hasMoreTokens()){
            char arr[] = st.nextToken().toCharArray();

            for(int i = 0; i < arr.length; i++) {
                if(i % 2 == 0) arr[i] = Character.toUpperCase(arr[i]);
                else arr[i] = Character.toLowerCase(arr[i]);

                answer += arr[i];
                al.add(String.valueOf(arr[i]));

            }
            answer += " ";
        }

        answer = answer.substring(0, answer.length() - 1);

        if(answer.length() == s.length()) return answer;

        answer.replace(" ", "");

        for(int i = 0; i < s.length(); i++)
            if(s.charAt(i) == ' ') al.add(i, " ");

        answer = "";

        for(String i : al) answer += i;

        return answer;
    }
}

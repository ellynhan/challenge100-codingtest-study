class Solution {
    public int solution(String t, String p) {
        int answer = 0;

        for(int i = 0; i<=t.length()-p.length(); i++){
            String result = "";
            for (int j = 0; j<p.length(); j++){
                result = result.concat(String.valueOf(t.charAt(i+j)));
            }
            if(Long.parseLong(result)<=Long.parseLong(p)) {
                 answer +=1;
             }
        }
        return answer;
    }
}
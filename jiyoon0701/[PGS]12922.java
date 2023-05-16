class Solution {
    public String solution(int n) {
        String answer = "";
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                answer = answer.concat("수");
            }else {
                answer = answer.concat("박");
            }
        }
        return answer;
    }
}

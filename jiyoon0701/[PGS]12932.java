class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        String an = String.valueOf(n);
        answer = new int[an.length()];
        for(int i = 0; i < an.length(); i++){
            answer[i] = Integer.parseInt(an.substring(an.length()-i-1,an.length()-i));
        }
        return answer;
    }
}

class Solution {
    public String solution(String phone_number) {
        String answer = "";
        int num = phone_number.length() - 4;
        answer = answer.concat("*".repeat(num));
        answer = answer.concat(phone_number.substring(num));
        return answer;
    }
}

class Solution {
    public String solution(String phone_number) {
        String answer = "";
        char arr[] = phone_number.toCharArray();

        for(int i = arr.length - 5; i >= 0; i--) arr[i] = '*';
        for (char c : arr) answer += c;

        return answer;
    }
}
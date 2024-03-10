// https://school.programmers.co.kr/learn/courses/30/lessons/12926
class Solution {
    public String solution(String s, int n) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == ' ') continue;
            if (Character.isUpperCase(arr[i])) arr[i] = (char)('A' + (arr[i]-'A'+n) % 26);
            if (Character.isLowerCase(arr[i])) arr[i] = (char)('a' + (arr[i]-'a'+n) % 26);
        }
        return new String(arr);
    }
}

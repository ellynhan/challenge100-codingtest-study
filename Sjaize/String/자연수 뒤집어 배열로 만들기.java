// https://school.programmers.co.kr/learn/courses/30/lessons/12932
class Solution {
    public int[] solution(long n) {
        String str = String.valueOf(n);
        String reversed = new StringBuilder(str).reverse().toString();
        char[] arr = reversed.toCharArray();
        int[] result = new int[arr.length];
        for (int i = 0; i < result.length; i++) result[i] = arr[i] - '0';
        return result;
    }
}

class Solution {
    public long[] solution(int x, int n) {
        long[] answer = {};
        answer = new long[n];
        long a = 0;
        for(int i = 1; i<=n; i++){
            a += (long)x;
            answer[i-1] = a;
        }
        return answer;
    }
}

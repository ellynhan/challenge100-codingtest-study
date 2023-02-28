class Solution {
    public int solution(int a, int b, int n) {
        // a = 2 b = 1 n = 20
        int answer = 0;

        while (a <= n) {
            answer+=(n/a) * b;
            n= (n/a) * b + (n%a);
        }
        return answer;
    }
}
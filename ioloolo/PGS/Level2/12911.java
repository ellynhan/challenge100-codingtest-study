class Solution {
    public int solution(int n) {
        int answer = n;
        int nZero = countZero(n);

        while (true) {
            answer++;

            if (countZero(answer) == nZero) {
                break;
            }
        }

        return answer;
    }

    private int countZero(int n) {
        int cnt = 0;

        for (char c : Integer.toBinaryString(n).toCharArray()) {
            if (c == '1') {
                cnt++;
            }
        }

        return cnt;
    }
}
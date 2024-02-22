// https://school.programmers.co.kr/learn/courses/30/lessons/68935
class Solution {
    public int solution(int n) {
        int answer = 0;
        int number = 1;
        int i = 1;
        while (n >= number * 3) number *= 3;
        while (n != 0) {
            answer += n / number * i;
            n = n % number;
            i *= 3;
            number /= 3;
        }
        return answer;
    }
}

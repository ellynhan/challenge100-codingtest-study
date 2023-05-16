
public class Solution {

    public int solution(int a, int b) {
        int answer = 0;

        int t = Integer.parseInt(String.valueOf(a) + String.valueOf(b));
        answer = 2 * a * b;

        return answer > t ? answer : t;
    }

}
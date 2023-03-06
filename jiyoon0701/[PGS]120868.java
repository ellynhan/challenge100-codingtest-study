import java.lang.Math;
class Solution {
    public int solution(int[] sides) {
        int answer = 0;
        int max_num = Math.max(sides[0],sides[1]);
        int min_num = Math.min(sides[0],sides[1]);
        int sum_num = sides[0] + sides[1];
        int count = max_num - (max_num - min_num);
        int count2 = sum_num - max_num - 1;
        answer = count + count2;
        return answer;
    }
}
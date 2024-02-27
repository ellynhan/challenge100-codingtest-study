// https://school.programmers.co.kr/learn/courses/30/lessons/42842
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] result = new int[2];
        int sum = (brown - 4) / 2;
        for (int col = 1; col < sum; col++) {
            int row = sum - col;
            if (col * row == yellow) {
                result[0] = row + 2;
                result[1] = col + 2;
                break;
            }
        }
        return result;
    }
}

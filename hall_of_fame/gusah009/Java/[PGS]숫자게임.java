import java.util.Arrays;

class Solution {

    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);
        int answer = 0;
        int p1 = 0, p2 = 0;
        while (p1 < A.length && p2 < B.length) {
            if (A[p1] < B[p2]) {
                answer++;
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        return answer;
    }
}
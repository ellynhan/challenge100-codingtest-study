
public class Solution {

    public int solution(int[][] sizes) {
        int answer = 0, max1 = 0, max2 = 0;

        for(int i = 0; i < sizes.length; i++) {

            if(sizes[i][0] > sizes[i][1]) {
                answer = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = answer;
            }

            max1 = Math.max(max1, sizes[i][0]);
            max2 = Math.max(max2, sizes[i][1]);

        }

        return max1 * max2;
    }

}
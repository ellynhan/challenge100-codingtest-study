class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        for(int a : arr){
            answer += a;
        }
        answer /= arr.length;
        return answer;
    }
}

// https://school.programmers.co.kr/learn/courses/30/lessons/68936
class Solution {
    private static int zero = 0;
    private static int one = 0;
    
    public int[] solution(int[][] arr) {
        count(arr, 0, 0, arr.length);
        return new int[] {zero, one};
    }
    
    private void count(int[][] arr, int row, int col, int length) {
        boolean compress = true;
        int start = arr[row][col];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (start != arr[row+i][col+j]) {
                    compress = false;
                    break;
                }
            }
        }
        if (compress) {
            if (start == 0) ++zero;
            else ++one;
            return;
        }
        int newLength = length/2;
        count(arr, row, col, newLength);
        count(arr, row + newLength, col, newLength);
        count(arr, row, col + newLength, newLength);
        count(arr, row + newLength, col + newLength, newLength);
    } 
}

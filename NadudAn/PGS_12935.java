public class Solution {
    public static int[] solution(int[] arr) {
        if(arr.length == 1) {
            int[] answer = { -1 };
            return answer;
        }

        int[] answer = new int[arr.length - 1];
        int min = arr[0];

        for(int i = 1; i < arr.length; i++)
            if(arr[i] < min) min = arr[i];

        int cnt = 0;

        for(int i = 0; i < arr.length; i++) {
            if (arr[i] != min) {
               answer[cnt] = arr[i];
               cnt++;
            }
        }

        return answer;
    }

}

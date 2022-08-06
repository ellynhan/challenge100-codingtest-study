class Solution {
    boolean solution(String s) {
        boolean answer;
        int cnt = 0;

        char arr[] = s.toLowerCase().toCharArray();

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == 'p') cnt++;
            if(arr[i] == 'y') cnt--;
        }

        if(cnt == 0) answer = true;
        else answer = false;

        return answer;
    }
}
class Solution {
    
    public boolean solution(int x) {
        boolean answer = true;
        int sum = 0, t = x;

        while(true) {
            if(t <= 0) break;

            sum += t % 10;
            t /= 10;
        }

        if(x % sum != 0) return false;

        return answer;
    }
}
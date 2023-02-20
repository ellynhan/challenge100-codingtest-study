
public class Solution {

    public int solution(int n) {
        if(n <= 1) return 0;
        int answer = 0;

        for(int i = 2; i <= n; i++)
            if(prime(i)) answer++;

        return answer;
    }

    public boolean prime(int n) {
        for(int i = 2; i <= Math.sqrt(n) + 1; i++) {
            if(n != i && n % i == 0) return false;
        }
        return true;
    }

}
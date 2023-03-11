
public class Solution {

    public long solution(long n) {
        long temp;

        temp = (long) Math.sqrt(n);
        if (Math.pow(temp, 2) == n) return (long) Math.pow(temp + 1, 2);

        return -1;
    }

}
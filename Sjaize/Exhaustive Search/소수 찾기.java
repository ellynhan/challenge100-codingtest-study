// https://school.programmers.co.kr/learn/courses/30/lessons/42839
import java.util.Arrays;
import java.util.Set;
import java.util.HashSet;

class Solution {
    private static Set<Integer> primes = new HashSet<>(); 
    
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    private void getPrimes(int acc, int[] numSet, boolean[] isUsed) {
        if (isPrime(acc)) primes.add(acc);
        
        for (int i = 0; i < numSet.length; i++) {
            if (isUsed[i]) continue;
            int nextAcc = acc * 10 + numSet[i];
            isUsed[i] = true;
            getPrimes(nextAcc, numSet, isUsed);
            isUsed[i] = false;
        }
    }
    
    public int solution(String numbers) {
        int[] numSet = numbers.chars().map(c -> c-'0').toArray();
        boolean[] isUsed = new boolean[numSet.length];
        getPrimes(0, numSet, isUsed);
        return primes.size();
    }
}

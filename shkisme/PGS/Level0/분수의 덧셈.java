class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int[] answer = {};
        
        numer1 *= denom2;
        numer2 *= denom1;
        
        int add = numer1 + numer2;
        int mult = denom1 * denom2;
        int gcd = gcd(add, mult);
        answer = new int[] {add / gcd, mult / gcd};
        return answer;
    }
    
    public int gcd(int p, int q){
        if (q == 0) return p;
        return gcd(q, p%q);
    }
}

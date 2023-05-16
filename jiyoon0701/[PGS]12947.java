class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int sum = 0;
        String xm = String.valueOf(x);
        for(int i = 0; i<xm.length(); i++){
            sum += xm.charAt(i) - '0';
        }
        if(x % sum != 0){
            answer = false;
        }
        return answer;
    }
}

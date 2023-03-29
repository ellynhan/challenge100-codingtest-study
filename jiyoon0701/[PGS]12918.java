class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        String[] a = s.split("");
        if(s.length() == 4 || s.length() == 6){
            for(String b : a){
                int nu = b.charAt(0);
                if(nu < 48 || nu > 57){
                    answer = false;
                }
            }
        }else {
            answer = false;
        }
       
        return answer;
    }
    
}

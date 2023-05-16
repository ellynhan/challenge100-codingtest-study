class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int f = 0;
        int d = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == 'p' || s.charAt(i) == 'P'){
                f+=1;
            }else if (s.charAt(i) == 'y' || s.charAt(i) == 'Y'){
                d+=1;
            }
        }
       
        if(f != d){
            answer = false;
        }

        return answer;
    }
}

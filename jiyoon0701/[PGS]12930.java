class Solution { 
    public String solution(String s) {
        String answer = "";
        String[] a = s.split("");
        int count = 0;
        for (int i =0; i<a.length; i++){
            if ((a[i]).charAt(0) == ' '){
                answer = answer.concat(" ");
                count = 0;
            }
            else if(count%2 == 0 && (int)((a[i]).charAt(0)) >96){
                String g = String.valueOf((char)((a[i]).charAt(0)-32));
                answer = answer.concat(g);
                count+=1;
            }
            else if(count%2 != 0 && (int)((a[i]).charAt(0)) <= 96){
                String g = String.valueOf((char)((a[i]).charAt(0)+32));
                answer = answer.concat(g);
                count+=1;
            }
            else {
                String g = String.valueOf((a[i]).charAt(0));
                answer = answer.concat(g);
                count+=1;
            }
        }
        return answer;
    }
}

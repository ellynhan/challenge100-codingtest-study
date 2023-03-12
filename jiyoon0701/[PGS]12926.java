class Solution {
    public String solution(String s, int n) {
        String answer = "";
        String[] alpa = s.split("");
        for(String al : alpa){
            int nums = ((int)(al.charAt(0)));
            
            if(al.equals(" ")){
                answer = answer.concat(" ");
            }
            else if(97 <= nums && nums <= 127)
            {
                nums += n;
                if(nums > 122){
                    nums = nums-26; 
                }
                answer = answer.concat(String.valueOf((char)nums));
            }
            else { // 대문자
                nums += n;
                if(nums > 90){
                    nums = nums-26; 
                }
                answer = answer.concat(String.valueOf((char)nums));
            }
        }
        return answer;
    }
}

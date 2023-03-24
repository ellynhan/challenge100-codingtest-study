class Solution {
    public int solution(int num) {
        int count = 0;
        int answer = 0;
        long nums = (long)num;
        while(nums > 1) {
            if(answer == 500){
                answer = -1;
                break;
            }
            if(nums % 2 == 0){
                nums = nums / 2;
            }else {
                nums = nums * 3 + 1;
            }
            answer+=1;
        }
       
        return answer;
    }
}

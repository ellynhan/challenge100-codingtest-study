class Solution { //0422 12:03~12:28 
    
public:
    int minMoves(int target, int maxDoubles) {
       
        int result = 0;
        while(target>1)
        {  
            if(maxDoubles<=0){
                result += target-1;
                break;
            }
         
            if(target%2==0 && maxDoubles>0){
            target = target/2;
            maxDoubles--;
            }else
                target--;
            result++;
         }
        return result;
    }
};

// 문제: https://leetcode.com/problems/minimum-moves-to-reach-target-score/
// 거꾸로 생각하기

class Solution {//0421 11:50~11:54
public:
    int numberOfSteps(int num) {
        int result =0;
        while(num>=1){
            num = num%2==0 ? num/2 : num-1;
            result++;
        }
        return result;
    }
};

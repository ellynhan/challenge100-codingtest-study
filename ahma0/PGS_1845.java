import java.util.ArrayList;

public class Solution {

    public int solution(int[] nums) {
        ArrayList arrayList = new ArrayList();

        for(int i = 0; i < nums.length; i++) {
            if(!arrayList.contains(nums[i])) arrayList.add(nums[i]);
        }

        if(nums.length / 2 <= arrayList.size()) return nums.length / 2;
        else return arrayList.size();
    }

}
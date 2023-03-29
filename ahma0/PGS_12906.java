import java.util.*;

public class Solution {

    public int[] solution(int []arr) {
        int t = -1;

        ArrayList<Integer> arrayList = new ArrayList<>();

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] != t) {
                arrayList.add(arr[i]);
                t = arr[i];
            }
        }

        return arrayList.stream().mapToInt(Integer::intValue).toArray();
    }

}
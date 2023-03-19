import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> arrayList = new ArrayList();

        Arrays.sort(arr);

        for(int i = 0; i < arr.length; i++)
            if(arr[i] % divisor == 0) arrayList.add(arr[i]);

        if(arrayList.isEmpty()) return new int[]{-1};

        return arrayList.stream().mapToInt(Integer::intValue).toArray();
    }

}
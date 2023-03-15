import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    public int[] solution(int k, int[] score) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        int[] arr;
        int cnt = k - 1;

        if(k > score.length) {
            cnt = score.length - 1;
            arr = new int[score.length];

            for(int i = 0; i < score.length; i++) {
                arr[0] = score[i];
                Arrays.sort(arr);
                arrayList.add(arr[cnt]);
                cnt--;
            }

            return arrayList.stream().mapToInt(Integer::intValue).toArray();
        }

        arr =  new int[k];

        for(int i = 0; i < k; i++) {
            arr[0] = score[i];
            Arrays.sort(arr);
            arrayList.add(arr[cnt]);
            cnt--;
        }

        Arrays.sort(arr);

        for(int i = k; i < score.length; i++) {
            for(int j = 0; j < k; j++) {
                if(arr[j] < score[i]) {
                    arr[j] = score[i];
                    break;
                }
            }
            Arrays.sort(arr);
            arrayList.add(arr[0]);
        }

        return arrayList.stream().mapToInt(Integer::intValue).toArray();
    }

}
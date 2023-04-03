import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class Solution {

    public int solution(int k, int m, int[] score) {
        int answer = 0;
        int arr[] = new int[m];

        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for(int i : score) queue.add(i);

        while(queue.size() >= m) {
            for(int i = 0; i < m; i++)
                arr[i] = queue.poll();

            Arrays.sort(arr);

            answer += arr[0] * m;
        }

        return answer;
    }

}

import java.util.Arrays;
import java.util.Stack;

public class Solution {

    public int[] solution(int[] numbers) {
        int[] arr = new int[numbers.length];

        Arrays.fill(arr, -1);

        Stack<Integer> stack = new Stack<>();
        stack.push(0);

        for(int i = 1; i < numbers.length; i++) {
            while (!stack.isEmpty() && numbers[stack.peek()] < numbers[i]) {
                arr[stack.pop()] = numbers[i];
            }

            stack.push(i);
        }

        return arr;
    }

}
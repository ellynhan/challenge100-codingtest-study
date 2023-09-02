import java.util.*;
class Solution {
    public String solution(String number, int k) {
        char[] result = new char[number.length() - k];
        Stack<Character> st = new Stack<>();

        for (int i=0; i<number.length(); i++) {
            char num = number.charAt(i);
            // 제일 위에 값이 num 보다 작을 때 change  & 제거 숫자 보다 더 제거가 되지 않도록
            while (!st.isEmpty() && st.peek() < num && k-- > 0) {
                st.pop();
            }
            st.push(num);
        }
        
        //  일반 string으로 계속 묶으면 메모리를 새로 차지하기 때문에 메모리 낭비
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < result.length; i++) {
            sb.append(st.get(i));
        }

        return sb.toString();
    }
}

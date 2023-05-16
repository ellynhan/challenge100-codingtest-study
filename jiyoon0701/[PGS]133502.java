import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        Stack<Integer> st = new Stack<Integer>();
        for(int in : ingredient){
            st.push(in);
            int size = st.size();
            if(size > 3 && st.peek() == 1 && st.get(size-2) == 3 && st.get(size-3) == 2 && st.get(size-4) == 1){
                st.pop();
                st.pop();
                st.pop();
                st.pop();
                answer+=1;
            }
        }
        return answer;
    }
}

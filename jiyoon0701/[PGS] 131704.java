import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        int n = order.length;

        Stack<Integer> stack = new Stack<>(); // 주 컨테이너
        
        for(int a = order.length; a > 0; a--){
            stack.push(a);
        }
        Stack<Integer> st = new Stack<>(); // 보조 컨테이너

        int first = order[0]; 
        
        for (int i = 1; i < first; i++) {
            st.push(i); // 보조 컨테이너에 들어있는 
            stack.pop(); // 주 남아있는  
        } // 처음으로 실어야 하는 박스 앞에 있는 박스를 컨테이너에 담아둔다.
        
        for (int f : order) { // 상자의 순서
            if (!st.isEmpty() && f == st.peek()) { // 보조 컨테이너에 상자가 있는 경우
                answer++;
                st.pop();
            } else if (!stack.isEmpty() && f == stack.peek()) { // 주 컨테이너에 상자가 있는 경우
                answer++;
                stack.pop();
            } else if(!st.contains(f)){ // 주 컨테이너에 해당 숫자가 있다면 보조 컨테이너로 옮긴다.
                int a = stack.search(f);
                if(a > -1){  // 주 컨테이너에 있따 
                    for(int g = 0; g < a; g++){
                        st.push(stack.pop()); 
                    } 
                    st.pop();
                    answer+=1;
                }
            }
            else {
                break;
            }   
        }

        return answer;
    }
}

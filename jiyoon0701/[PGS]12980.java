import java.util.*;
import java.util.stream.Collectors;
class Solution
{
    public int solution(String s)
    {
        
        Stack<Character> st = new Stack<>();
        
        for(char a : s.toCharArray()) {
            if(!st.empty() && st.peek() == a) {
                st.pop();
            } else {
                st.push(a);
            }
        }
         return st.empty() ? 1 : 0; 
      
    }
}
import java.util.*;
class Solution {
    public void print(List<String>list){
        for(int i=0;i<list.size();i++){
            System.out.print(list.get(i)+" ");
        }
        System.out.println();
    }
    public int solution(String s) {
        List<String>list=new LinkedList<>();
        Stack<String>stack=new Stack<>();
        int answer=0;
        for (int i = 0; i < s.length(); i++) {
            list.add(String.valueOf(s.charAt(i)));
        }
        for(int i=0;i<s.length();i++){
            stack.clear();
            if(i!=0){
                list.add(list.remove(0));
            }
            // print(list);
            
            for(int k=0;k<list.size();k++){
                // System.out.println("stack:"+stack.size());
                
                if(stack.empty()){
                    stack.add(list.get(k));
                }else if(list.get(k).equals("[")||list.get(k).equals("(")||list.get(k).equals("{")){
                    stack.add(list.get(k));
                }else{
                    if(list.get(k).equals("}")){
                        if(stack.peek().equals("{")){
                            stack.pop();
                        }else{
                            break;
                        }
                    }else if(list.get(k).equals(")")){
                        if(stack.peek().equals("(")){
                            stack.pop();
                        }else{
                            break;
                        }
                    }else if(list.get(k).equals("]")){
                        if(stack.peek().equals("[")){
                            stack.pop();
                        }else{
                            break;
                        }
                    }
                }
            }
            // System.out.println("answer : "+answer);
            if(stack.size()==0){
                answer++;
            }
        }
        return answer;
    }
}

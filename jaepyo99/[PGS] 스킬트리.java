import java.util.*;
class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        Stack<Integer>stack=new Stack<>();
        for(int i=0;i<skill_trees.length;i++){
            System.out.println("answer: "+answer);
            System.out.println("new");
            stack.clear();
            boolean val=true;
            for(int j=0;j<skill.length();j++){
                int cnt=0;
                for(int k=0;k<skill_trees[i].length();k++){
                    stack.forEach(System.out::print);
                    System.out.println("\n"+"k: "+k+" skill:"+skill.charAt(j)+" skill_tree[i]:"+skill_trees[i].charAt(k));
                    if(skill.charAt(j)==skill_trees[i].charAt(k)){
                        if(stack.size()==0){
                            stack.push(k);
                            break;
                        }
                        else if(stack.peek()<k){
                            stack.push(k);
                            break;
                        }
                        else{
                            val=false;
                            break;
                        }
                    }else{
                        cnt++;
                    }
                }
                if(!val){
                    break;
                }
                if(cnt==skill_trees[i].length()){
                    stack.push(27);
                }
            }
            if(val){
                answer++;
            }
        }        
        return answer;
    }
}

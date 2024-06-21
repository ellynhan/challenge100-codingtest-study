import java.util.*;
class Solution {
    int answer;
    Set<Set<String>>ans_set=new HashSet<>();
    String[]userIds;
    String[]banIds;
    public boolean isBan(String user,String ban){
        if(user.length()!=ban.length()){
            return false;
        }
        for(int i=0;i<user.length();i++){
            if(ban.charAt(i)=='*'){
                continue;
            }
            if(!(ban.charAt(i)==user.charAt(i))){
                return false;
            }
        }
        return true;
    }
    
    public void dfs(Set<String>set,int depth){
        if(depth==banIds.length){
            ans_set.add(set);
            return;
        }
        for(int i=0;i<userIds.length;i++){
            if(set.contains(userIds[i])){
                continue;
            }
            if(isBan(userIds[i],banIds[depth])){
                set.add(userIds[i]);
                dfs(new HashSet<>(set),depth+1);
                set.remove(userIds[i]);
            }
        }
    }
    
    
    public int solution(String[] user_id, String[] banned_id) {
        answer = 0;
        boolean[]visit_user=new boolean[user_id.length];
        userIds=user_id;
        banIds=banned_id;
        dfs(new HashSet<>(),0);
        
        return ans_set.size();
    }
}

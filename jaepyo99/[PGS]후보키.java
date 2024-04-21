import java.util.*;
class Solution {
    List<String>candi=new ArrayList<>();
    public int solution(String[][] relation) {
        int answer = 0;
        int r=relation[0].length;
        for(int i=0;i<r;i++){
            boolean[]visit=new boolean[r];
            dfs(visit,0,0,i+1,relation);
        }
        return candi.size();
    }
    void dfs(boolean[]visit,int start,int depth,int end,String[][]relation){
        if(end==depth){
            List<Integer>list=new ArrayList<>();
            String key="";
            for(int i=0;i<visit.length;i++){
                if(visit[i]){
                    key+=String.valueOf(i);
                    list.add(i);
                }
            }
            Map<String,Integer>map=new HashMap<>();
            for(int i=0;i<relation.length;i++){
                String s="";
                for(Integer j:list){
                    s+=relation[i][j];
                }
                if(map.containsKey(s)){
                    return;
                }else{
                    map.put(s,0);
                }
            }
            for(String s:candi){
                int cnt=0;
                for(int i=0;i<key.length();i++){
                    String sub=String.valueOf(key.charAt(i));
                    if(s.contains(sub)){
                        cnt++;
                    }
                }
                if(cnt==s.length()){
                    return;
                }
            }
            candi.add(key);
            return;
        }
        
        for(int i=start;i<visit.length;i++){
            if(visit[i]){
                continue;
            }
            visit[i]=true;
            dfs(visit,i,depth+1,end,relation);
            visit[i]=false;
        }
    }
}

import java.util.*;
class Solution {
    static boolean[]visit;
    static int depth;
    public int solution(int[] cards) {
        int answer = 1;
        int len=cards.length;
        visit=new boolean[len+1];
        List<Integer>list=new ArrayList<>();
        for(int i=0;i<len;i++){
            if(!visit[i+1]){
                depth=1;
                visit[i+1]=true;
                dfs(cards[i],cards);
                list.add(depth);
            }
        }
        if(list.size()<2){
            return 0;
        }
        Collections.sort(list,Collections.reverseOrder());
        answer=list.get(0)*list.get(1);
        return answer;
    }
    public void dfs(int card,int[]cards){
        if(!visit[card]){
            visit[card]=true;
            depth+=1;
            dfs(cards[card-1],cards);
        }
    }
}

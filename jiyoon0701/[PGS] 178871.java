import java.util.*;
class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int idx = 0; idx < players.length; idx++){
            map.put(players[idx], idx);
        }
   
        for(String call : callings){
            int index = map.get(call); // 추월한 선수의 index
            String play = players[index-1]; // 추월당한 선수의 이름
            players[index-1] = call;
            players[index] = play;
            map.put(call, index-1);
            map.put(play, index);
        }
        answer = players.clone();
        return answer;
    }
}

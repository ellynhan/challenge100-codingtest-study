import java.util.*;

class Solution {
    public static int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<progresses.length; i++)
             q.offer((100-progresses[i])%speeds[i] == 0 ? (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i]+1);

        List<Integer> list = new ArrayList<>();
        int cnt = 1;
        int x = q.poll();
        while(!q.isEmpty()) {
            if(x >= q.peek()) {
                cnt++;
                q.poll();
            }
            else {
                list.add(cnt);
                cnt = 1;
                x = q.poll();
            }
        }
        list.add(cnt);

        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++)
            answer[i] = list.get(i);
        return answer;
    }
}

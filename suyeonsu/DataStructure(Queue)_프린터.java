import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    static class Job {
        int idx;
        int priority;

        public Job(int idx, int priority) {
            this.idx = idx;
            this.priority = priority;
        }
    }

    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Job> q = new LinkedList<>();
        for(int i=0; i<priorities.length; i++) {
            q.offer(new Job(i, priorities[i]));
        }

        while(!q.isEmpty()) {
            int max = Integer.MIN_VALUE;
            for(Job job : q) {
                max = Math.max(max, job.priority);
            }
            while(q.peek().priority != max) q.offer(q.poll());
            answer++;
            if(q.peek().idx == location) break;
            q.poll();
        }
        return answer;
    }
    
}

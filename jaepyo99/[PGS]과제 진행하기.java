import java.util.*;
class Solution {
    public class Task{
        private String name;
        private int start;
        private int playTime;
        public Task(String name,int start,int playTime){
            this.name=name;
            this.start=start;
            this.playTime=playTime;
        }
        public Task(String name,int playTime){
            this.name=name;
            this.playTime=playTime;
        }
    }
    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        int idx=0;
        PriorityQueue<Task>pq=new PriorityQueue<>(
            (o1,o2)->(o1.start-o2.start)
        );
        for(int i=0;i<plans.length;i++){
            String name=plans[i][0];
            String[]str=plans[i][1].split(":");
            
            int h=Integer.parseInt(str[0]);
            int m=Integer.parseInt(str[1]);
            int start=(h*60)+m;
            
            int time=Integer.parseInt(plans[i][2]);
            
            pq.add(new Task(name,start,time));
        }
        Stack<Task>remainingTasks=new Stack<>();
        
        while(!pq.isEmpty()){
            Task currentTask=pq.poll();
            String curName=currentTask.name;
            int curStart=currentTask.start;
            int curPlayTime=currentTask.playTime;
            
            int currentTime=curStart;
            
            if(!pq.isEmpty()){
                Task nextTask=pq.peek();
                
                if(currentTime+curPlayTime<nextTask.start){
                    answer[idx++]=curName;
                    currentTime+=curPlayTime;
                    while(!remainingTasks.isEmpty()){
                        Task rem=remainingTasks.pop();
                        if(currentTime+rem.playTime<=nextTask.start){
                            currentTime+=rem.playTime;
                            answer[idx++]=rem.name;
                            continue;
                        }else{
                            int t=rem.playTime-(nextTask.start-currentTime);
                            remainingTasks.push(new Task(rem.name,t));
                            break;
                        }
                    }
                }else if(curStart+curPlayTime==nextTask.start){
                    answer[idx++]=curName;
                    continue;
                }else{
                    int t=nextTask.start-currentTime;
                    remainingTasks.push(new Task(curName,curPlayTime-t));
                }
            }else{
                if(remainingTasks.isEmpty()){
                    currentTime+=curPlayTime;
                    answer[idx++]=curName;
                }else{
                    answer[idx++]=curName;
                    while(!remainingTasks.isEmpty()){
                        Task rem=remainingTasks.pop();
                        answer[idx++]=rem.name;
                    }
                }
            }
        }
        
        return answer;
    }
}

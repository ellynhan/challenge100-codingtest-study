import java.util.*;
class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        PriorityQueue<String>pq=new PriorityQueue<>();
        for(int i=0;i<timetable.length;i++){
            pq.offer(timetable[i]);
        }
        int cm=0;
        String lastTimeTable=timetable[0];
        String time="09:00";
        while(n>0){
            // System.out.println("===");
            n--;
            cm=0;
            for(int i=0;i<m;i++){
                String now;
                if(!pq.isEmpty()){
                    now=pq.peek();
                    // System.out.println("now : "+now);
                    
                }else{
                    break;
                }
                if(calTime(now)<=calTime(time)){
                    cm++;
                    lastTimeTable=pq.poll();
                    // System.out.println("changeLastTimeTable : "+lastTimeTable);
                }else{
                    break;
                }
            }
            if(n>0){
                time=changeTime(time,t);
            }   
            // System.out.println("time : "+time);
            // System.out.println("lastTimeTable : "+lastTimeTable);
            
        }
        if(cm<m){
            return time;
        }else{
            return changeTime(lastTimeTable,-1);
        }
    }
    public String changeTime(String now,int change){
        String[] time=now.split(":");
        String h=time[0];
        String m=time[1];
        Integer ih=Integer.parseInt(h);
        Integer im=Integer.parseInt(m);
        im=im+change;
        if(im<0){
            ih=ih-1;
            im=im+60;    
        }else{
            ih=ih+im/60;
            im=im%60;    
        }
        return String.format("%02d:%02d",ih,im);
    }
    public Integer calTime(String time){
        String[] t=time.split(":");
        String h=t[0];
        String m=t[1];
        Integer ih=Integer.parseInt(h);
        Integer im=Integer.parseInt(m);
        return ih*60+im;
    }
} 

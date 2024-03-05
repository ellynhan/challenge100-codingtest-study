import java.util.*;
class Solution {
    public String[] solution(int[][] line) {
        String[]answer;
        HashSet<Pointer>pSet=new HashSet<>();
        long xmin=Long.MAX_VALUE,xmax= Long.MIN_VALUE;
        long ymin=Long.MAX_VALUE,ymax= Long.MIN_VALUE;
        for(int i=0;i<line.length-1;i++){
            long a=line[i][0];
            long b=line[i][1];
            long e=line[i][2];
            for(int j=i+1;j<line.length;j++){
                
                long c=line[j][0];
                long d=line[j][1];
                long f=line[j][2];
                if((a*d-b*c)==0){
                    continue;
                }
                if((b*f-e*d)%(a*d-b*c)!=0){
                    continue;
                }
                if((e*c-a*f)%(a*d-b*c)!=0){
                    continue;
                }
                long x=((b*f-e*d)/(a*d-b*c));
                long y=((e*c-a*f)/(a*d-b*c));
                pSet.add(new Pointer(x,y));
                xmin=Math.min(xmin,x);
                xmax=Math.max(xmax,x);
                ymin=Math.min(ymin,y);
                ymax=Math.max(ymax,y);
            }
        }
        long h=ymax-ymin+1;
        long w=xmax-xmin+1;
        answer=new String[(int)h];
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<w;i++){
            sb.append(".");
        }
        Arrays.fill(answer,sb.toString());
        
        long nx,ny;
        for(Pointer p:pSet){
            ny=ymax-p.y;
            nx=p.x-xmin;
            answer[(int)ny]=answer[(int)ny].substring(0,(int)nx)+"*"+answer[(int)ny].substring((int)nx+1);
        }
        
        return answer;
    }
    public class Pointer{
        long x;
        long y;
        public Pointer(long x,long y){
            this.x=x;
            this.y=y;
        }
    }
}

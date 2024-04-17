import java.util.*;
class Solution {
    public double[] solution(int k, int[][] ranges) {
        double[] answer = new double[ranges.length];
        List<Integer>height=new ArrayList<>();
        List<Double>area=new ArrayList<>();
        while(true){
            if(k==1){
                height.add(k);
                break;
            }
            if(k%2==0){
                height.add(k);
                k/=2;
                
            }else{
                height.add(k);
                k=k*3+1;
            }
        }
        int n=height.size();
        for(int i=0;i<n-1;i++){
            Double now_area=(double)(height.get(i)+height.get(i+1))/2;
            area.add(now_area);
        }
        for(int i=0;i<ranges.length;i++){
            double result=0;

            for(int j=ranges[i][0];j<n+ranges[i][1]-1;j++){
                result+=area.get(j);
            }
            if(ranges[i][0]>n+ranges[i][1]-1){
                result-=1;
            }
            answer[i]=result;
        }
        
        return answer;
    }
}

import java.util.*;
class Solution {
    List<int[]>arr=new ArrayList<>();
    public void hanoi(int n,int start,int mid,int end){
        if(n==0){
            return;
        }
        hanoi(n-1,start,end,mid);
        arr.add(new int[]{start,end});
        hanoi(n-1,mid,start,end);
    }
    public int[][] solution(int n) {
        hanoi(n,1,2,3);
        int[][]answer=new int[arr.size()][2];
        for(int i=0;i<arr.size();i++){
            answer[i]=arr.get(i);
        }        
        return answer;
    }
}

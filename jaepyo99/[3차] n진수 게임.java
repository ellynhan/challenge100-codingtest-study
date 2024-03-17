import java.util.*;
class Solution {
    private static String change(int n,int num){
        List<String>s=new ArrayList<>();
        StringBuilder sb=new StringBuilder();
        if(num==0){
            return "0";
        }
        while(num>0){
            int tmp=num%n;
            if(tmp>9){
                int m=tmp-10;
                sb.append(Character.toString('A'+m));
                num=num/n;
                continue;
            }
            sb.append(String.valueOf(tmp));
            num=num/n;
        }
        sb.reverse();
        return sb.toString();

    }
    public static String solution(int n, int t, int m, int p) {
        String answer = "";
        int num=1;
        int turn;
        int a=0;
        for(turn=0;;turn++){
            String say=change(n,turn);
            for(int i=0;i<say.length();i++){
                if(num==p){
                    answer=answer+say.charAt(i);
                    a++;
                }
                if(a>=t){
                    return answer;
                }
                num=(num+1)%(m+1);
                if(num==0){
                    num=1;
                }
            }
        }
    }
}
// 0(이거) 1 2 3 4
// 0 1 10 11 100
    

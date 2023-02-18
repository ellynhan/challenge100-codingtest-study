// N개 수열, 연속된부분수열의 합이 M이 되는 경우의 수

// 고려. 마지막 종료조건

// 로직.
//  for  rt증가 sum > M -> lt증가 sum <= M

import java.util.*;

class Main{

    public static int sol(int n, int m, ArrayList<Long> gg){
        int ans = 0; // 경우의수
        int comp = 0; // M과 비교
        int lt = 0, rt = 0;

        while(lt<n){
            if(rt == n && comp<m) break;
            else if(comp<m) comp += gg.get(rt++);
            else if(comp==m) {ans+=1; comp-=gg.get(lt++);}
            else comp-=gg.get(lt++);
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Long> gg = new ArrayList<>();
        for(int i=0; i<n; i++){
            gg.add(sc.nextLong());
        }

        System.out.print(sol(n,m,gg));

    }
}
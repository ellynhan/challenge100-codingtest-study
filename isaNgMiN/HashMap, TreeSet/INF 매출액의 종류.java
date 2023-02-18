// 중복이 제거된 매출액의 종류

// 로직. for문 돌면서 Set으로 저장 -> ans.add(set.size())

import java.util.*;

class Main{

    public static ArrayList<Integer> sol(int n, int k, long[] gg){
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Long, Integer> tans = new HashMap<>();

        //init
        for(int j=0; j<k; j++){
            tans.put(gg[j], tans.getOrDefault(gg[j], 0)+1);
        }
        ans.add(tans.keySet().size());

        int lt=0;
        for(int rt=k; rt<n; rt++){
            if(tans.get(gg[lt])==1) tans.remove(gg[lt++]);
            else {tans.put(gg[lt], tans.get(gg[lt])-1); lt++;}
            tans.put(gg[rt], tans.getOrDefault(gg[rt],0)+1);
            ans.add(tans.keySet().size());
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] gg = new long[n];
        for(int i=0; i<n; i++){
            gg[i] = sc.nextLong();
        }

        ArrayList<Integer> ans = sol(n,k,gg);
        for(Integer x:ans){
            System.out.print(x + " ");
        }
    }
}
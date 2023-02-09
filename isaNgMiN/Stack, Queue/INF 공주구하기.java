// 1~N 동그라미 / K번째순번은 제외 / 다음순번부터 다시 1~K / 한사람이 남을때까지

// 로직.
//  큐를 써서 계속 돌리면 되는거 아님?

import java.util.*;


class Main{

    public static int sol(int n, int k){
        int ans = 0;
        Queue<Integer> q = new LinkedList<>();

        for(int i=1; i<=n; i++){
            q.add(i);
        }

        int cnt = 0;
        while(q.size() != 1){
            cnt++;
            if(cnt == k) {q.poll(); cnt = 0;}
            else {
                q.add(q.poll());
            }
        }
        ans = q.poll();

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        System.out.print(sol(n,k));

    }
}
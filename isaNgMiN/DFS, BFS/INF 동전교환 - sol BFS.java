// 요소의 조합의 sum = m (거스름돈)

// bfs
//  3갈래. d가 깊어짐에 따라. 더한다
//  총합이 15가 되면 종료
//  총합이 15를 넘어가면 return


import java.util.*;

class Main{

    public static int bfs(int n, int m, int[] t){
        Queue<Integer> bq = new LinkedList<>();
        bq.add(0);
        int d = 0;

        while(!bq.isEmpty()){
            d+=1;
            int sz = bq.size();
            for(int i=0; i<sz; i++) {
                int sum = bq.poll();
                for (int x : t) {
                    if (sum + x > m) continue;
                    else if (sum + x == m) return d;
                    else bq.add(sum + x);
                }
            }
        }
        return d;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }
        int m = sc.nextInt();

        System.out.print(bfs(n,m,t));
    }
}
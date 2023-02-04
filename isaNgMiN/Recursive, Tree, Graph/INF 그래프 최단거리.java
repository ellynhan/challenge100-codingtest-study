// 1번에서 각정점으로 가는 최소 이동 간선수


import java.util.*;

class Main{

    public static HashMap<Integer, Integer> bfs(int n, int m, ArrayList<ArrayList<Integer>> g){
        HashMap<Integer, Integer> ans = new HashMap<>();
        int[] check = new int[n+1];
        check[1] = 1;

        Queue<Integer> bq = new LinkedList<>();
        bq.add(1);

        for(int i = 0; i <= n ; i ++){
            ans.put(i, 0);
        }

        while(!bq.isEmpty()){
            int tmp = bq.poll();
            for(int x: g.get(tmp)){
                if(check[x] != 1) {
                    check[x] =1;
                    bq.add(x);
                    ans.put(x, ans.get(tmp) + 1);
                }
            }
        }


        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();

        for(int i=0; i<=n; i++){
            g.add(new ArrayList<Integer>());
        }

        for(int i=0;i<m;i++){
            g.get(sc.nextInt()).add(sc.nextInt());
        }

        HashMap<Integer, Integer> ans = bfs(n,m,g);
        for(int i = 2; i <= n ; i ++){
            System.out.println(i + " : " + ans.get(i));
        }


    }
}
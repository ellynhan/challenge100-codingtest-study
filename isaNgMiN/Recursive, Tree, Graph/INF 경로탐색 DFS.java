// N번 정점까지 갈 수 있는 모든 경우의 수

// 로직
//  ㅇ. 방향그래프 배열 초기화
//  2. check 배열 초기화
//  3. 경로탐색 (check 배열 신경써)

import java.util.*;


class Main{

    static int[] check;
    static int path = 0;
    static int[][] g;
    static int n;
    static ArrayList<Integer> pn = new ArrayList<>();

    public static void dfs(int node){
        if(node == n){
            pn.add(node);
            path+=1;
            int pn_s = pn.size();
            for(int i=0; i<pn_s;i++) {System.out.print(pn.get(i));}
            pn.clear();
            System.out.println();
        }else{
            for(int i=1; i<=n; i++) {
                if (i == node) continue;
                if (check[i] != 1 && g[node][i] == 1) {
                    check[i] = 1;
                    pn.add(node);
                    dfs(i);
                    check[i] = 0;
                }
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int m = sc.nextInt();
        g = new int[m+1][m+1];
        for(int i=1; i<=m; i++){
            g[sc.nextInt()][sc.nextInt()] = 1;
        }
        check = new int[n+1];
        check[1] = 1;

        dfs(1);
        System.out.print(path);

    }
}
// N명 M번의 테스트가 등수로 주어짐 -> 멘토멘티 순서쌍 totalnum
//  멘토 A: M번의시험 모두 A>B
//      N M
//      test1 ranking
//      test2 ranking
//      testM ranking

// 예외. 학생 0번은 없다
// 예외. 같은 등수는 없다

// 로직. for1. 1->N 모든 학생에 대하여
//          for2. 각 시험에서
//              for3. 멘티의 대상자를 정제. 넣고 뺀다

import java.util.*;

class Main{

    public static int sol(int n, int m, int[][] tttt) {
        int ans = 0; // 순서쌍수

        HashSet<Integer> tans = new HashSet<>(), comp;

        for (int i = 1; i <= n; i++) {
            for(int x=1; x<=n; x++){
                if(i==x) continue;
                tans.add(x);
            }
            for (int j = 0; j < m; j++) {
                for (int k = 1; k <= n; k++) {
                    if(i == tttt[j][k]) break;
                    tans.remove(tttt[j][k]);
                }
            }
            ans += tans.size();
            tans = new HashSet<>();
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] tttt = new int[m][n+1];
        for(int i=0; i<m; i++){
            for (int j=1; j<=n; j++){
                tttt[i][j] = sc.nextInt();
            }
        }

        System.out.print(sol(n,m,tttt));
    }
}

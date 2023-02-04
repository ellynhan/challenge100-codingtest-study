// 오름차순 두배열 -> 오름차순 한배열

// 고려. 크기가 서로 다름

// 로직.
//  (ㅇ) 기본. for문을 돌며 비교 -> 삽입 + 포인터 뒤로 ->
//  (ㅇ) 마무리. 한쪽이 다 들어가면 나머지 모두 삽입
//  (ㅇ) 예외. 같을때

// 리스트 이어붙이기
import java.util.*;

class Main{


    public static long[] sol(int n, int m, long[] g1, long[] g2){
        long[] ans = new long[n+m];
        int p1 = 0, p2 = 0;

        for(int i=0; i<n+m; i++){
            if(p1 == n) {ans[i] = g2[p2]; p2++;}
            else if(p2 == m) {ans[i] = g1[p1]; p1++;}
            else if(g1[p1] < g2[p2]) {ans[i] = g1[p1]; p1++;}
            else if(g1[p1] > g2[p2]) {ans[i] = g2[p2]; p2++;}
            else {ans[i] = g1[p1]; p1++;}
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] g1 = new long[n];
        for(int i=0; i<n; i++){
            g1[i] = sc.nextLong();
        }
        int m = sc.nextInt();
        long[] g2 = new long[m];
        for(int i=0; i<m; i++){
            g2[i] = sc.nextLong();
        }

        long[] ans = sol(n,m,g1,g2);
        for(int i=0; i<n+m; i++){
            System.out.print(ans[i] + " ");
        }

    }
}
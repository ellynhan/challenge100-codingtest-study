// LRU 가장 오랫동안 사용하지 않은 것 제거. 앞이 최신 뒤가 오래된거. 숫자는 인덱스일뿐
// cache miss 해야할 작업이 캐시에 없을 때 -> 새로운 작업을 맨앞에 + 가장 오래된거 삭제(가장 뒤에 있는거 삭제)
// cache hit 해야할 작업이 캐시에 있을 때 -> 해당 작업을 가장 앞으로. 나머지는 한칸씩 뒤로
// 처음에는 캐시가 비어진 상태

//로직.
// 1. for  S -> N-1
//      if 캐시에 있다: 해당번호 템프, 해당번호 앞에거 한칸씩 뒤로. 맨앞에
//      else 캐시에 없다: 마지막 삭제. 한칸씩 뒤로. 맨앞에


// 배열 포함
import java.util.*;

class Main{

    public static long[] sol(int s, int n, long[] t){
        long[] ans = new long[s];

        for(int i=0; i<n; i++){
            int idx = -1;
            for(int j=0; j<s; j++){
                if(ans[j] == t[i]) idx = j;
            }
            if(idx != -1) { // 캐싱
                for(int j=idx; j>0; j--){
                    ans[j] = ans[j-1];
                }
            }
            else{// 노캐싱
                for(int j=s-1; j>0; j--){
                    ans[j] = ans[j-1];
                }
            }
            ans[0] = t[i];
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int s  = sc.nextInt();
        int n = sc.nextInt();
        long[] t = new long[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }

        long[] ans = sol(s,n,t);
        for(long x:ans) System.out.print(x + " ");
    }
}
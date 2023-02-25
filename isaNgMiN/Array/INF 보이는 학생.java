// N 앞에 있는 모든 수보다 크면 true / 하나라도 보다작거나 같으면 false
// true 수 출력

// 예외. 같음 처리
// 예외. 맨앞처리

// 로직. true를 기준으로 보다 크면 +, 작으면 continue;


import java.util.*;

class Main{

    public static int sol(int n, long[] ff){
        int ans = 1;
        long comp = ff[0];

        for(long x : ff){
            if(comp >= x) continue;
            else{
                ans += 1;
                comp = x;
            }
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] ff = new long[n];
        for (int i=0; i<n; i++){
            ff[i] = sc.nextInt();
        }

        System.out.print(sol(n,ff));

    }
}
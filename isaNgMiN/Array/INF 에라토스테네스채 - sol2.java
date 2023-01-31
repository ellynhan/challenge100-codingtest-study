// n까지의 소수의 개수

// 예외. 1제외

// 로직. checking 배열. n까지의 배열을 1로 초기화한 다음 0으로 삭제시키며. 마지막에 totalnum
//      삭제는 시작부터 배수로. 만약에 시작이 지워져있다면 continue;
//      for 2->n/2
//      인덱스 == 숫자 / 인덱스 0과 1 0으로 초기화


// 로직2. 지나간걸 카운팅. 1일때만 동작

import java.util.*;

class Main{

    public static int sol(int n){
        int ans = 0;
        int[] tans = new int[n+1];
        for (int i=0; i<n+1; i++){
            tans[i] = 1;
        }
        tans[0] = 0; tans[1] = 0;

        for(int i=2; i<=n; i++){
            if(tans[i] == 1) ans+=1;
            for(int j=2; i*j<=n; j++){
                tans[i*j] = 0;
            }
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.print(sol(n));
    }
}
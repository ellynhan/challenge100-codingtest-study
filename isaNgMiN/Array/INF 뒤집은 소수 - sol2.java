// N개의 숫자 입력 -> 숫자를 뒤집었을때 소수가 되는 수를 소수로 출력

// 예외. 뒤집었을때 첫자리 0은 무시

// 로직. 수를 뒤집는다. j->n 소수인지 판별한다

import java.util.*;

class Main{

    public static boolean isPrime(long g){
        if(g == 1) return false;
        else{
            for(int i=2; i<=g/2; i++){
                if(g%i == 0) return false;
            }
        }
        return true;
    }
    public static ArrayList<Long> sol(int n, long[] gg){
        ArrayList<Long> ans = new ArrayList<>();

        for (int i=0; i<n; i++){
            long tans = 0;
            while(0 < gg[i]){
                long tmp = gg[i]%10;
                tans = tans*10+tmp;
                gg[i] = gg[i]/10;
            }

            if(isPrime(tans) == true) ans.add(tans);
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] gg = new long[n];
        for(int i=0; i<n; i++){
            gg[i] = sc.nextLong();
        }

        ArrayList<Long> ans = sol(n, gg);
        for(int i=0; i<ans.size(); i++){
            System.out.print(ans.get(i) + " ");
        }
    }
}
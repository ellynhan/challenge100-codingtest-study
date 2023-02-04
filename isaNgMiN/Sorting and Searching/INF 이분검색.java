// 이분검색

// 로직
//  1. 오름차순 정렬 -> sort
//  2. M 바이너리 서치. 몇번째에 있는가 -> 1/2

import java.util.*;

class Main{

    public static int sol(int n, int m, int[] t){
        int ans = 0;

        Arrays.sort(t);

        int lt=0, rt=t.length-1;
        while(lt<=rt){
            int mid = (lt+rt)/2;
            if(t[mid] == m) return mid+1;
            else if(t[mid] < m) lt = mid+1;
            else rt = mid-1;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] t = new int[n];
        for(int i=0; i<n; i++){
            t[i] = sc.nextInt();
        }

        System.out.println(sol(n,m,t));
    }
}


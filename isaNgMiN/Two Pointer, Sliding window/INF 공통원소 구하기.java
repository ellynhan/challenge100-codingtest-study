// 두배열의 ·교집합, 오름차순정렬· 출력

// 고려. 한배열내에 중복원소는 없다

// 로직.
// 1. 정렬
// 2. 투포인트 공동원소추출

import java.util.*;

class Main{

    public static ArrayList<Long> sol(int n, int m, ArrayList<Long> gg1, ArrayList<Long> gg2){
        ArrayList<Long> ans = new ArrayList<>();
        int p1 = 0, p2 = 0;

        gg1.sort(Comparator.naturalOrder());
        gg2.sort(Comparator.naturalOrder());

        while(p1<n && p2<m){
            if(gg1.get(p1).equals(gg2.get(p2))) {ans.add(gg1.get(p1++)); p2++;}
            else if(gg1.get(p1) > gg2.get(p2)) p2++;
            else p1++;
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Long> gg1 = new ArrayList<>();
        for (int i=0; i<n; i++){
            gg1.add(sc.nextLong());
        }
        int m = sc.nextInt();
        ArrayList<Long> gg2 = new ArrayList<>();
        for (int i=0; i<m; i++){
            gg2.add(sc.nextLong());
        }

        ArrayList<Long> ans = sol(n,m,gg1,gg2);
        for (Long x: ans){System.out.print(x + " ");}

    }

}
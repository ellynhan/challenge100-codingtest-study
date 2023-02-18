// 정렬되어 있는데 철수랑 짝꿍만 자리바꿈
// 철수번호 짝꿍번호 (바뀐 인덱스 찾기)

// 로직
// 작아지는 인덱스 저장
// 예외. 바꿨는데 키가 같을 수 있다

import java.util.*;

class Main{

    public static ArrayList<Integer> sol(int n, int[] t){
        ArrayList<Integer> ans = new ArrayList<>();

        ArrayList<Integer> comp = new ArrayList<>();
        for(int i=0; i<=n; i++){
            comp.add(t[i]);

        }
        Arrays.sort(t);

        for (int i=1; i<=n; i++){
            if(!comp.get(i).equals(t[i])) ans.add(i);
            if(ans.size() == 2) break;
        }


        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n+1];
        for (int i=1; i<=n; i++){
            t[i] = sc.nextInt();
        }

        ArrayList<Integer> ans = sol(n,t);
        for(int x: ans) {System.out.print(x + " ");}
    }
}


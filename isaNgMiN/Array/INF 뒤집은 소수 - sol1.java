import java.util.*;

class Main{

    public static ArrayList<Long> sol(int n, long[] gg){
        ArrayList<Long> ans = new ArrayList<>();


        for(int i=0; i<n; i++){
            Long tans = Long.parseLong(new StringBuilder(String.valueOf(gg[i])).reverse().toString()); // 뒤집은수
            if(tans == 1) continue;

            ans.add(tans);
            for(int j=2; j<=tans/2; j++){
                if(tans%j == 0) ans.remove(tans);
            }
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
import java.util.*;

class Main{

    public static ArrayList<Integer> sol(int n, int[] ff){
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(ff[0]);
        int comp = ff[0];

        for (int x : ff){
            if (comp < x) ans.add(x);
            comp = x;
        }
        return ans;
    }


    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ff = new int[n];
        for (int i=0; i<n; i++){
            ff[i] = sc.nextInt();
        }

        ArrayList<Integer> ans = sol(n,ff);
        for (int i=0; i<ans.size(); i++){
               System.out.print(ans.get(i) + " ");
        }
    }
}
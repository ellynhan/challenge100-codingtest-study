import java.util.*;

class Main{

    public static ArrayList<Character> sol(int n, int[] ffa, int[] ffb){
        ArrayList<Character> ans = new ArrayList<>();

        for (int i=0; i<n; i++){
            if(ffa[i] == ffb[i]) ans.add('D');
            else if(ffa[i] == 1 && ffb[i] == 3) ans.add('A');
            else if(ffa[i] == 2 && ffb[i] == 1) ans.add('A');
            else if(ffa[i] == 3 && ffb[i] == 2) ans.add('A');
            else ans.add('B');
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ffa = new int[n];
        for (int i=0; i<n; i++){
            ffa[i] = sc.nextInt();
        }
        int[] ffb = new int[n];
        for (int i=0; i<n; i++){
            ffb[i] = sc.nextInt();
        }
        ArrayList<Character> ans = sol(n, ffa, ffb);
        for (char x:ans){
            System.out.println(x);
        }

    }
}
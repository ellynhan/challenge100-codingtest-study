import java.util.*;

class Main{

    public static ArrayList<String> solution(int n, String[] ss){
        ArrayList ans = new ArrayList<>();

        for(String x : ss){
            String tans = new StringBuilder(x).reverse().toString();
            ans.add(tans);
        }
        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] ss = new String[n];
        for (int i=0; i<n; i++){
            ss[i] = sc.next();
        }

        ArrayList<String> ans = solution(n, ss);
        for(String x : ans){
            System.out.println(x);
        }
    }
}
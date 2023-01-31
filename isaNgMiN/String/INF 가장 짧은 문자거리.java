import java.util.*;

class Main{

    public static int[] sol(String s, char c){
        int[] ans = new int[s.length()];
        for (int i=0; i < ans.length; i++){
            ans[i] = Integer.MAX_VALUE;
        }

        int cnt=0;
        int start = s.indexOf(c);

        for (int i=start; i<s.length(); i++){
            if(s.charAt(i) == c){
                cnt = 0;
            }else {
                cnt++;
            }
            ans[i] = cnt;
        }

        start = s.lastIndexOf(c);
        for (int i=start; i>=0; i--){
            if(s.charAt(i) == c){
                cnt = 0;
            }else {
                cnt++;
            }
            if(ans[i] > cnt) {
                ans[i] = cnt;
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char c = sc.next().charAt(0);

        int[] ans = sol(s, c);
        for(int i=0; i<s.length(); i++) {
            System.out.print(ans[i] + " ");
        }
    }
}
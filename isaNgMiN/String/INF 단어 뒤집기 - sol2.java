import java.util.*;
class Main {
    public static ArrayList<String> solution(int n, String[] s){
        ArrayList<String> ans = new ArrayList<>();

        for (String x : s){
            char[] cc = x.toCharArray();
            int lt = 0; int rt = x.length()-1;

            while(lt<rt){
                char tmp = cc[lt];
                cc[lt] = cc[rt];
                cc[rt] = tmp;
                lt++;
                rt--;
            }

            ans.add(String.valueOf(cc));
        }
        return ans;
    }


    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);
        int n=kb.nextInt();
        String[] s=new String[n];
        for(int i=0; i<n; i++){
            s[i]=kb.next();
        }
        for(String x : solution(n, s)){
            System.out.println(x);
        }
    }
}
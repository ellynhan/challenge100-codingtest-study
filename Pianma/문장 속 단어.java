import java.util.*;

class Main {

    public String  solution(String str) {
        String answer = "";
        String s[] =  str.split(" ");
        int n =0;
        for(String x : s){
            if(x.length()>n){
                n = x.length();
                answer = x;
            }
        }


        return answer;
    }

    public static void main(String[] args) {
      Main T = new Main();
      Scanner sc = new Scanner(System.in);
      String str  = sc.nextLine();

       
      System.out.println(T.solution(str));
    }
}

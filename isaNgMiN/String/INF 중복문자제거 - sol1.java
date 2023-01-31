// 소문자로 된 한개의 문자열
// 중복문자제거 출력


import java.util.*;

class Main{

    public static String solution(String s){
        String ans="";
        ArrayList<Character> cc = new ArrayList<>();

        for (char x : s.toCharArray()){
            if (cc.contains(x)){
                continue;
            }else{
                cc.add(x);
                ans += x;
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(solution(s));

    }

}
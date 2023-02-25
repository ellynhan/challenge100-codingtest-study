// (()) 괄호 옳바른 쌍

// 로직.
//  1. 여는괄호 스택인
//  2. 닫는괄호 스택아웃
//            아웃할게 없으면 false

import java.util.*;

class Main{

    public static String sol(String s){
        String ans = "YES";
        Stack<Character> ori = new Stack<>();

        for(char x : s.toCharArray()){
            if(x == '(') ori.push('(');
            else{
                if(ori.isEmpty()) return "NO";
                else ori.pop();
            }
        }
        if(!ori.isEmpty()) return "NO";

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }
}
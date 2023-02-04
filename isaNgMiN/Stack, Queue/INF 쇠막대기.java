// 잘린개수 구하는 문제

// () 레이저
// 떨어진 () 나무토막

// 로직. for 1 -> N
//     레이저닫는괄호 +스택size / 나무닫는괄호 +1
//          어떻게 구분하는가. 이전 인덱스참조

import java.util.*;

class Main{

    public static int sol(String s){
        int ans = 0;
        Stack<Character> sta = new Stack<>();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '(') sta.push('(');
            else{
                if(s.charAt(i-1) == '('){// lazer
                    sta.pop();
                    if(!sta.isEmpty()) ans += sta.size();
                }else{
                    sta.pop();
                    ans += 1;
                }
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.print(sol(s));
    }
}
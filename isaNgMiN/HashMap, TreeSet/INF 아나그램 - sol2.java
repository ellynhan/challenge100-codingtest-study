//알파벳의 구성동일여부. 구성과 개수까지. 대소문자구분

// 로직
//  HashMap에 기록
//  키에대한 값이 다르면 false
//  size가 다르면 false

import java.util.*;

class Main{

    public static String sol(String s1, String s2){
        String ans = "YES";
        HashMap<Character, Integer> h1 = new HashMap<>();

        for(Character x : s1.toCharArray()){
            h1.put(x, h1.getOrDefault(x, 0)+1);
        }
        for(Character x : s2.toCharArray()){
            if(!h1.containsKey(x) || h1.get(x) == 0) return "NO";
            h1.put(x,h1.get(x)-1);
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();

        System.out.print(sol(s1, s2));
    }
}
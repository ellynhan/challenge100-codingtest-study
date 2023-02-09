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
        HashMap<Character, Integer> h2 = new HashMap<>();

        for(Character x : s1.toCharArray()){
            h1.put(x, h1.getOrDefault(x, 0)+1);
        }
        for(Character x : s2.toCharArray()){
            h2.put(x, h2.getOrDefault(x, 0)+1);
        }

        if(h1.size() != h2.size()) return "NO";

        for(Map.Entry<Character, Integer> e : h1.entrySet()){
            if(e.getValue() != h2.get(e.getKey())) return "NO";
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
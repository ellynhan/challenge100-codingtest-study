// 가장 많은 득표수 (사람, 득표수)

// 로직. hashmap으로 저장
//  O 동율 X

import java.util.*;

class Main{

    public static Character sol(int n, String s){
        Character ans = null;
        HashMap<Character, Integer> m = new HashMap<>();

        for(char x : s.toCharArray()){
            if(m.keySet().contains(x)){
                m.put(x, m.get(x)+1);
            }
            else{
                m.put(x,1);
            }
        }

        Integer tans = Collections.max(m.values());

        for(Character key : m.keySet()){
            if(tans.equals(m.get(key))){
                ans = key;
            }
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();

        System.out.print(sol(n,s));
    }
}
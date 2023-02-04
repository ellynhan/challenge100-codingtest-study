// 부분요소가 순서가 지켜져 있어야한다

// 로직.대조하면서 counting

import java.util.*;

class Main{

    public static String sol(String f, String s){
        String ans ="NO";
        Queue<Character> q = new LinkedList<>();
        for(char x : f.toCharArray() ){
            q.offer(x);
        }
        for(Character x : s.toCharArray()) {
            if(x.equals(q.peek())){
                q.poll();
            }
            if(q.isEmpty()) return "YES";
        }

        return ans;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String f = sc.next();
        String s = sc.next();

        System.out.print(sol(f,s));
    }
}
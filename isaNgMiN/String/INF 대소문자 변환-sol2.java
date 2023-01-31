import java.util.*;

class Main{
    public static String solution(String str){
        String answer="";
        for(char x : str.toCharArray()){
            if(x>=97 && x<=122) answer+=(char)(x-32);
            else answer+=(char)(x+32);
        }
        return answer;
    }

    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);
        String str=kb.next();

        System.out.print(solution(str));
    }
}


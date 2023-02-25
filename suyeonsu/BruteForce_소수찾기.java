import java.util.*;

public class Solution {

    static int n, r;
    static char[] ch;
    static boolean[] visited;
    static int[] sel;
    static HashSet<Integer> nums = new HashSet<>();

    public static int solution(String numbers) {
        ch = numbers.toCharArray();
        n = ch.length;
        for(int k=1; k<=n; k++) {
            visited = new boolean[n];
            r = k;
            sel = new int[r];
            permutations(0);
        }

        int answer = 0;
        for(Object o : nums.toArray())
            if(isPrime((Integer)o)) answer++;
        return answer;
    }

    private static void permutations(int cnt) {
        if(cnt == r) {
            StringBuilder sb = new StringBuilder();
            for(int e : sel) sb.append(e);
            nums.add(Integer.parseInt(sb.toString()));
            return;
        }
        for(int i=0; i<ch.length; i++) {
            if(!visited[i]) {
                sel[cnt] = Integer.parseInt(String.valueOf(ch[i]));
                visited[i] = true;
                permutations(cnt+1);
                visited[i] = false;
            }
        }
    }

    private static boolean isPrime(int num) {
        if(num == 0 || num == 1) return false;
        if(num == 2) return true;
        for(int i=2; i<num; i++)
            if(num%i == 0) return false;
        return true;
    }
}

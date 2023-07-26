import java.util.*;
import java.io.*;

public class BOJ12852 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Map<Integer,Integer> visit = new HashMap<>();
        
        Queue<Integer> bfs = new ArrayDeque<>();

        int n = scanner.nextInt();
        visit.put(n, n);
        bfs.offer(n);
        
        while(!bfs.isEmpty()){

            int now = bfs.poll();
            if(now == 1)
                break;

            if(now % 3 == 0 && !visit.containsKey(now / 3)){
                visit.put(now / 3, now);
                bfs.offer(now / 3);
            }
            if(now % 2 == 0 && !visit.containsKey(now / 2)){
                visit.put(now / 2, now);
                bfs.offer(now / 2);
            }
            if(!visit.containsKey(now - 1)){
                visit.put(now - 1, now);
                bfs.offer(now - 1);
            }
        }

        List<Integer> ans = new ArrayList<>();
        int cnt = 0;
        int value = 1;
        
        while(value != n){
            ans.add(value);
            cnt++;
            value = visit.get(value);
        }
        ans.add(n);

        StringBuilder str = new StringBuilder();
        str.append(cnt);
        str.append('\n');
        
        for (int i = ans.size() - 1; i >= 0; i--) {
            str.append(ans.get(i));
            str.append(' ');
        }
        System.out.println(str);
        scanner.close();
    }
}

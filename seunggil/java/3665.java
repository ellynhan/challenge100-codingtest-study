import java.util.*;
import java.io.*;

public class _BOJ_TP_G1_3665 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int testCase = Integer.parseInt(re.readLine());
        StringBuilder ans = new StringBuilder();
        for(int t = 1; t <= testCase; t++){
            int n = Integer.parseInt(re.readLine());

            int[] rank = new int[n+1];
            StringTokenizer token = new StringTokenizer(re.readLine());
            for(int i = 1; i <= n; i++){
                rank[i] = Integer.parseInt(token.nextToken());
            }

            // rank[i][j] = 1 => i번째 팀이 j번째 팀보다 위
            // rank[i][j] = -1 => i번째 팀이 j번째 팀보다 밑
            int[][] rankedMap = new int[n+1][n+1];
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    rankedMap[rank[i]][rank[j]] = 1;
                    rankedMap[rank[j]][rank[i]] = -1;
                }
            }
            int[] degree = new int[n+1];

            int reverseCnt = Integer.parseInt(re.readLine());
            for(int i = 0; i < reverseCnt; i++){
                token = new StringTokenizer(re.readLine());
                int a = Integer.parseInt(token.nextToken());
                int b = Integer.parseInt(token.nextToken());

                // swap
                int temp = rankedMap[a][b];
                rankedMap[a][b] = rankedMap[b][a];
                rankedMap[b][a] = temp;
            }
            
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(rankedMap[i][j] == 1){
                        degree[i]++;
                    }
                }
            }

            boolean ambiguous = false;
            int visited = 0;
            List<Integer> rankAns = new ArrayList<>((int)(n*1.4));
            Queue<Integer> bfs = new ArrayDeque<>();

            for(int i = 1; i <= n; i++){
                if(degree[i] == 0)
                    bfs.add(i);
            }

            while(!bfs.isEmpty()){
                if(!ambiguous && bfs.size() > 1){
                    ambiguous = true;
                }

                int now = bfs.poll();
                rankAns.add(now);
                visited++;

                for(int i = 1; i <= n; i++){
                    if(rankedMap[i][now] == 1){
                        if(--degree[i] == 0)
                            bfs.add(i);
                    }
                }
            }

            if(visited != n){
                ans.append("IMPOSSIBLE").append('\n');
            }else if(ambiguous){
                ans.append('?').append('\n');
            }else{
                ListIterator<Integer> iter = rankAns.listIterator(rankAns.size());
                while(iter.hasPrevious())
                    ans.append(iter.previous()).append(' ');
                ans.append('\n');
            }
        }
        System.out.print(ans);
        
        re.close();
    }
}

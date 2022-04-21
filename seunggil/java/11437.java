import java.util.*;
import java.io.*;

public class _BOJ_LCA_G3_11437 {

    static int lca(int[]parent, int[] depth, int a, int b){
        while(depth[a] != depth[b]){
            if(depth[a] > depth[b]){
                a = parent[a];
            }else{
                b = parent[b];
            }
        }

        while(a != b){
            a = parent[a];
            b = parent[b];
        }
        return a;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());
        int[] parent = new int[n+1];
        boolean[] visited = new boolean[n+1];
        int[] depth = new int[n+1];

        List<List<Integer>> edges = new ArrayList<>(n+2);
        for(int i = 0; i < n+1; i++){
            edges.add(new ArrayList<>());
        }

        for(int i = 0; i < n-1; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());

            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        parent[1] = 1;
        visited[1] = true;
        depth[1] = 0;

        Queue<Integer> bfs = new ArrayDeque<>();
        bfs.add(1);

        int nowDepth = 0;
        while(!bfs.isEmpty()){
            for(int i = 0, size = bfs.size(); i < size; i++){
                int now = bfs.poll();
                for(int iter : edges.get(now)){
                    if(!visited[iter]){
                        visited[iter] = true;
                        parent[iter] = now;
                        depth[iter] = nowDepth+1;
                        bfs.add(iter);
                    }
                }
            }
            nowDepth++;
        }
        
        int queryCnt = Integer.parseInt(re.readLine());

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < queryCnt; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());
            ans.append(lca(parent, depth, a,b)).append('\n');
        }
        System.out.print(ans);

        re.close();
    }
}

import java.util.*;
import java.io.*;

public class _BOJ_LCA_P5_11438{
    static List<List<Integer>> inputData;
    static int[] depth;
    static int[] parent;
    static boolean []visited;
    static int setParent(boolean []visited, int now, int nowDepth){
            depth[now] = nowDepth;

            int maxDepth = nowDepth;
            for(int next : inputData.get(now)){
                if(!visited[next]){
                    visited[next] = true;
                    parent[next] = now;
                    maxDepth = Integer.max(maxDepth, setParent(visited, next, nowDepth+1));
                }
            }
            
            return maxDepth;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());
        
        inputData = new ArrayList<>((int)((n+1) * 1.4));

        for(int i = 0; i <= n; i++){
            inputData.add(new ArrayList<>());
        }

        for(int i = 0; i < n-1; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());

            inputData.get(a).add(b);
            inputData.get(b).add(a);
        }

        parent = new int[n+1];
        depth = new int[n+1];

        visited = new boolean[n+1];
        visited[1] = true;
        int maxDepth = setParent(visited, 1, 0);

        int logN = (int)Math.ceil(Math.log10(maxDepth) / Math.log10(2));
        int[][] ancestor = new int[n+1][logN];

        for(int i = 0; i <= n; i++){
            ancestor[i][0] = parent[i];
        }

        for(int i = 1; i < logN; i++){
            for(int j = 2; j <= n; j++){
                int p = ancestor[j][i-1];
                ancestor[j][i] = ancestor[p][i-1];
            }
        }

        int query = Integer.parseInt(re.readLine());
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < query; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int a = Integer.parseInt(token.nextToken());
            int b = Integer.parseInt(token.nextToken());

            // 첫 번째가 더 깊은 노드가 오게.
            if(depth[a] < depth[b]){
                int temp = a;
                a = b;
                b = temp;       
            }
            while(depth[a] != depth[b]){
                // 무조건 a가 더 깊은 노드임.
                for(int j = logN-1; j >= 0; j--){
                    if(ancestor[a][j] != 0 && depth[ancestor[a][j]] >= depth[b]){
                        a = ancestor[a][j];
                        break;
                    }
                }
            }

            if(a == b){
                ans.append(a).append('\n');
            }else{
                for(int j = logN-1; j >= 0; j--){
                    if(ancestor[a][j] != 0 && ancestor[a][j] != ancestor[b][j]){
                        a = ancestor[a][j];
                        b = ancestor[b][j];
                    }
                }
    
                ans.append(ancestor[a][0]).append('\n');
            }
            
        }
        System.out.println(ans);

        re.close(); 
    }
}
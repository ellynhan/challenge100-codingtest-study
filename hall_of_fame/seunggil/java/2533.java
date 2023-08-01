import java.util.*;
import java.io.*;

class Node{
    boolean earlyAdaptor = false;
    int parent = 1;
    List<Integer> children = new ArrayList<>();
    int degree;
}

public class _BOJ_DP_G3_2533 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        Node[] tree = new Node[n+1];
        for(int i = 1; i < n+1; i++){
            tree[i] = new Node();
        }
        for(int i = 0; i < n-1; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int from = Integer.parseInt(token.nextToken());
            int to = Integer.parseInt(token.nextToken());

            tree[from].children.add(to);
            tree[to].children.add(from);
        }

        boolean[] visited = new boolean[n+1];
        Queue<Integer> bfs = new ArrayDeque<>();

        visited[1] = true;
        tree[1].parent = -1;
        bfs.add(1);
        while(!bfs.isEmpty()){
            int now = bfs.poll();
            for(int iter : tree[now].children){
                if(!visited[iter]){
                    visited[iter] = true;
                    tree[iter].parent = now;
                    bfs.add(iter);
                }
            }
        }
        tree[1].degree = tree[1].children.size();
        for(int i = 2; i < n+1; i++){
            Node iter = tree[i];
            iter.degree = iter.children.size()-1;
            if(iter.degree == 0)
                bfs.add(i);
        }

        int answer = 0;
        while(!bfs.isEmpty()){
            Node now = tree[bfs.poll()];

            for(int iter : now.children){
                if(iter == now.parent)
                    continue;

                if(!tree[iter].earlyAdaptor){
                    now.earlyAdaptor = true;
                    answer++;
                    break;
                }
            }
            if(now.parent != -1){
                Node parent = tree[now.parent];
                parent.degree -= 1;
                if(parent.degree == 0 && now.parent != -1)
                    bfs.add(now.parent);
            }
            
        }

        System.out.print(answer);
        re.close();
    }
}

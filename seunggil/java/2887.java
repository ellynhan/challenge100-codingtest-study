import java.util.*;
import java.io.*;

public class BOJ_G1_2887_행성터널 {
    static int[] parent;
    
    static int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    static boolean union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);

        if(parentX == parentY)
            return false;
        if(parentX > parentY)
            parent[parentX] = parentY;
        else
            parent[parentY] = parentX;
        return true;
    }
    static class Edge{
        int from;
        int to;
        int value;
        public Edge(int from, int to, int value) {
            this.from = from;
            this.to = to;
            this.value = value;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());
        
        parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        // pos, index
        List<int[]> xData = new ArrayList<>(n);
        List<int[]> yData = new ArrayList<>(n);
        List<int[]> zData = new ArrayList<>(n);

        for(int i = 0; i < n; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int x = Integer.parseInt(token.nextToken());
            int y = Integer.parseInt(token.nextToken());
            int z = Integer.parseInt(token.nextToken());

            xData.add(new int[]{x,i});
            yData.add(new int[]{y,i});
            zData.add(new int[]{z,i});
        }

        xData.sort((int[] a, int []b )->{
            return Integer.compare(a[0], b[0]);
        });
        yData.sort((int[] a, int []b )->{
            return Integer.compare(a[0], b[0]);
        });
        zData.sort((int[] a, int []b )->{
            return Integer.compare(a[0], b[0]);
        });
        
        
        // // {a, b , value}
        //List<Edge> edges = new ArrayList<>(3*(n-1)+1);
        PriorityQueue<Edge> edges = new PriorityQueue<>(3*(n-1),(Edge a, Edge b)->{
            return Integer.compare(a.value, b.value);
        });

        for(int i = 0; i < n-1; i++){
            edges.add(new Edge(xData.get(i)[1], xData.get(i+1)[1], Math.abs(xData.get(i)[0] - xData.get(i+1)[0])));
        }
        for(int i = 0; i < n-1; i++){
            edges.add(new Edge(yData.get(i)[1], yData.get(i+1)[1], Math.abs(yData.get(i)[0] - yData.get(i+1)[0])));
        }
        for(int i = 0; i < n-1; i++){
            edges.add(new Edge(zData.get(i)[1], zData.get(i+1)[1], Math.abs(zData.get(i)[0] - zData.get(i+1)[0])));
        }

        int answer = 0;

        while(n != 1 && !edges.isEmpty()){
            Edge select = edges.poll();
            if(union(select.from, select.to)){
                answer += select.value;
                n--;
            }
        }

        System.out.print(answer);
        re.close();
    }
}
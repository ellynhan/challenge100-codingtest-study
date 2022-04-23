import java.util.*;
import java.io.*;

class Path implements Comparable<Path>{
    int to;
    int length;

    public Path(int to, int length) {
        this.to = to;
        this.length = length;
    }

    @Override
    public int compareTo(Path o) {
        return Integer.compare(length, o.length);
    }
}

public class _BOJ_SP_P5_5719 {
    static int shortestLength;
    static int ans;
    static boolean dijkstra(int[][] map, int start, int end){
        final int INF = 10_000_000;
        int node = map.length;

        boolean[] checked = new boolean[node];
        int[] distance = new int[node];
        Set<Integer>[] prev = new Set[node];

        for(int i = 0; i < node; i++)
            distance[i] = INF;
        for(int i = 0; i < node; i++){
            prev[i] = new HashSet<>();
        }

        checked[start] = true;
        distance[start] = 0;

        PriorityQueue<Path> pq = new PriorityQueue<>();
        for(int i = 0; i < node; i++){
            if(start == i)
                continue;

            if(distance[i] > distance[start] + map[start][i]){
                distance[i] = distance[start] + map[start][i];
                prev[i].clear();
                prev[i].add(start);
                pq.add(new Path(i,distance[i]));
            }else if(distance[i] != INF && distance[i] == distance[start] + map[start][i]){
                prev[i].add(start);
            }
        }

        while(!pq.isEmpty()){
            int to = pq.peek().to;
            int length = pq.poll().length;
            if(checked[to])
                continue;

            checked[to] = true;
            
            // 도착헀으면
            if(to == end){
                // 처음 발견한 최단 경로.
                if(shortestLength == INF){
                    shortestLength = distance[to];
                    continue;
                // 또 다른 최단 경로
                }else if(shortestLength == distance[to]){
                    continue;
                // 최단 거리보다 긴 거리 => 거의 최단 경로 (정답)
                }else if(shortestLength < distance[to]){
                    ans = distance[to];
                    return false;
                }else{ // 최단 거리 삭제 했는데, 또 최단거리 나오면 => 로직 오류.
                    assert false;
                }
            }

            // 현재 위치에서 다른 경로 갱신.
            for(int i = 0; i < node; i++){
                if(to == i || map[to][i] == INF)
                    continue;
    
                if(distance[i] > distance[to] + map[to][i]){
                    distance[i] = distance[to] + map[to][i];
                    prev[i].clear();
                    prev[i].add(to);
                    pq.add(new Path(i,distance[i]));
                }else if(distance[i] == (distance[to] + map[to][i])){
                    prev[i].add(to);
                }
            }
        }
        if(prev[end].isEmpty())
            return false;
        
        Queue<Integer> bfs = new ArrayDeque<>();
        bfs.add(end);
        while(!bfs.isEmpty()){
            int now = bfs.poll();
            for(int iter : prev[now]){
                map[iter][now] = INF;
                bfs.add(iter);
            }
            prev[now].clear();
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        //File file = new File("almost.in");
        //BufferedReader re = new BufferedReader(new FileReader(file));
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        final int INF = 10_000_000;
        StringBuilder ansString = new StringBuilder();
        while(true){
            shortestLength = INF;
            ans = -1;

            StringTokenizer token = new StringTokenizer(re.readLine());
            int node = Integer.parseInt(token.nextToken());
            int edge = Integer.parseInt(token.nextToken());
            if(node == 0 && edge == 0)
                break;

            token = new StringTokenizer(re.readLine());
            int start = Integer.parseInt(token.nextToken());
            int end = Integer.parseInt(token.nextToken());

            int[][] map = new int[node][node];

            for(int i = 0; i < node; i++)
                Arrays.fill(map[i], INF);
            
            for(int i = 0; i < edge; i++){
                token = new StringTokenizer(re.readLine());
                map[Integer.parseInt(token.nextToken())][Integer.parseInt(token.nextToken())] = Integer.parseInt(token.nextToken());
            }
            while(dijkstra(map, start, end));
            ansString.append(ans).append('\n');
        }
        
        System.out.print(ansString);
        re.close();
    }
}

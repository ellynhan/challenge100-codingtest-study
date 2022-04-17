import java.util.*;
import java.io.*;

class Pos{
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    double getLength(Pos other){
        return Math.sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
    }
}

public class Main{
    static int minX = Integer.MAX_VALUE;
    static int minY = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        List<Pos> inputData = new ArrayList<>(n+1);
        
        for(int i = 0; i < n; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int x = Integer.parseInt(token.nextToken());
            int y = Integer.parseInt(token.nextToken());
            char c = token.nextToken().charAt(0);
            if(c == 'Y'){
                inputData.add(new Pos(x,y));
                if(x < minX){
                    minX = x;
                    minY = y;
                }else if(x == minX && y < minY){
                    minY = y;
                }
            }
        }

        // 출발지 제외한 나머지 점들을 각도, 거리를 이용해 반시계 방향으로 정렬
        inputData.sort((a,b)->{
            int v1X = a.x - minX;
            int v1Y = a.y - minY;

            int v2X = b.x - minX;
            int v2Y = b.y - minY;

            Long result = 1L * v1X * v2Y - 1L * v2X * v1Y;
            if(result == 0){
                return Long.compare((1L * v1X * v1X + 1L * v1Y * v1Y), (1L * v2X * v2X + 1L * v2Y * v2Y));
            }else{
                return Long.compare(0,result);
            }
        });
        // 시작 위치를 마지막에 한번 더 추가.
        inputData.add(inputData.get(0));
        
        ArrayDeque<Integer> grahamScan = new ArrayDeque<>(inputData.size());
        List<ArrayDeque<Integer>> backups = new ArrayList<>();
        ArrayDeque<Integer> backup = new ArrayDeque<>();
        backups.add(backup);

        for(int i = 0, length = inputData.size(); i < length; i++){
            while(grahamScan.size() >= 2){
                Pos now = inputData.get(i);
                int prevIdx = grahamScan.pollLast();
                Pos prev = inputData.get(prevIdx);
                Pos pprev = inputData.get(grahamScan.peekLast());

                int x12 = prev.x - pprev.x;
                int y12 = prev.y - pprev.y;
                int x23 = now.x - prev.x;
                int y23 = now.y - prev.y;

                long degree = 1L * (x12) * (y23) - 1L * (y12) * (x23);

                // 반시계방향
                if(degree > 0){
                    grahamScan.add(prevIdx);
                    break;
                // 0도이거나 180도.
                }else if(degree == 0){
                    double dot = (1.0 * x12 * x23 + 1.0 * y12 * y23) / (Math.sqrt(1L * x12 * x12 + 1L * y12 * y12) * Math.sqrt(1L * x23 * x23 + 1L * y23 * y23));

                    if(Math.abs(dot - 1.0) <= 0.0001){
                        grahamScan.add(prevIdx);
                        break;
                    // 각도 180
                    }else if(Math.abs(dot + 1.0) <= 0.0001){

                    }else{
                        assert false;
                    }
                }
                
                // 시계 방향이거나 두 벡터의 사이각이 180도일때, 해당 좌표는 따로 빼둔다.
                if(backup.isEmpty() || (backup.peekLast() + 1 == prevIdx)){
                    backup.add(prevIdx);
                }
                else{
                    if(!backup.isEmpty()){
                        backup = new ArrayDeque<>();
                        backup.add(prevIdx);
                        backups.add(backup);
                    }
                }
            }

            grahamScan.add(i);
        }
        if(backups.get(backups.size()-1).isEmpty())
            backups.remove(backups.size()-1);
            
        StringBuilder ansPrint = new StringBuilder();
        ansPrint.append(inputData.size()-1).append('\n');
        int backupsIdx = 0;
        for(int i = 0, length = inputData.size() - 1; i < length; i++){
            int now = grahamScan.pollFirst();
            Pos nowPos = inputData.get(now);
            ansPrint.append(nowPos.x).append(' ').append(nowPos.y).append('\n');

            if(now != i){
                backup = backups.get(backupsIdx);
                Pos front = inputData.get(backup.peekFirst());
                Pos back = inputData.get(backup.peekLast());

                Iterator<Integer> iter;
                if(Math.sqrt(Math.pow(nowPos.x - front.x,2)+Math.pow(nowPos.y - front.y,2)) <= Math.sqrt(Math.pow(nowPos.x - back.x,2)+Math.pow(nowPos.y - back.y,2))){
                    iter = backups.get(backupsIdx).iterator();
                }else{
                    iter = backups.get(backupsIdx).descendingIterator();
                }
                while(iter.hasNext()){
                    nowPos = inputData.get(iter.next());
                    ansPrint.append(nowPos.x).append(' ').append(nowPos.y).append('\n');
                }
                ++backupsIdx;
                i = now;
            }
        }
        
        System.out.print(ansPrint);
        re.close();
    }
}
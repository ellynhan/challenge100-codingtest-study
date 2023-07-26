import java.util.*;
import java.io.*;

public class BOJ_UNKNOWN_G2_17143 {
    
    static class Shark{
        int dir;
        int speed;
        int size;

        public Shark(int dir, int speed, int size) {
            this.dir = dir;
            this.speed = speed;
            this.size = size;
        }
    }

    static class SharkLocation{
        int x;
        int size;

        public SharkLocation(int x, int size) {
            this.x = x;
            this.size = size;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());

        int r = Integer.parseInt(token.nextToken());
        int c = Integer.parseInt(token.nextToken());
        int sharkCnt = Integer.parseInt(token.nextToken());

        Shark[][] fishingmap1 = new Shark[r][c];
        Shark[][] fishingmap2 = new Shark[r][c];

        // location, size
        SharkLocation lowShark = new SharkLocation(200, -1);

        for(int i = 0; i < sharkCnt; i++){
            token = new StringTokenizer(re.readLine());
            int x = Integer.parseInt(token.nextToken()) -1;
            int y = Integer.parseInt(token.nextToken()) -1;
            int speed =  Integer.parseInt(token.nextToken());
            int dir = Integer.parseInt(token.nextToken());
            int weight =  Integer.parseInt(token.nextToken());

            // 방향 위 1, 아래 4, 왼쪽 2, 오른쪽 3으로 변경. 5-dir하면 방향 반대로 되게.
            if(dir == 2)
                dir = 4;
            else if(dir == 4){
                dir = 2;
            }
            fishingmap1[x][y] = new Shark(dir, speed, weight);

            // 다음에 낚시할 구역에서 x좌표와 가장 가까운 상어 선택
            if((y == 0) && (lowShark.x > x)){
                lowShark.size = weight;
                lowShark.x = x;
            }
        }

        boolean isEven = true;
        int ans = 0;
        // 낚시 시작
        for(int i = 0; i < c; i++){
            Shark[][] nowMap;
            Shark[][] nextMap;

            if(isEven){
                nowMap = fishingmap1;
                nextMap = fishingmap2;
            }
            else{
                nowMap = fishingmap2;
                nextMap = fishingmap1;
            }

            // 해당 열에 물고기 있으면
            if(lowShark.x != 200){
                ans += lowShark.size;

                // 선택한 물고기는 없애기
                nowMap[lowShark.x][i] = null;
                lowShark.size = -1;
                lowShark.x = 200;
            }
            
            if(i == c-1) // 마지막이면 상어를 이동 할 필요 없다.
                continue;

            // 상어 이동.
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    if(nowMap[j][k] != null){
                        Shark s = nowMap[j][k];
                        if(s.dir == 1 || s.dir == 4){
                            // 위치 계산
                            int location;
                            if(s.dir == 1)
                                location = (j-s.speed) % (2*r -2);
                            else
                                location = (j+s.speed) % (2*r -2);

                            if(location < 0){
                                location = -location;
                                s.dir = 5-s.dir;
                            }
                            if(location >= r){
                                location = (2*r - 2) - location;
                                s.dir = 5-s.dir;
                            }

                            if((nextMap[location][k] == null) || (nextMap[location][k].size < s.size)){
                                nextMap[location][k] = s;

                               // 바로 다음에 낚시할 곳이면 해당 열 제일 작은 x좌표 찾기.
                                if((k == i+1) && (lowShark.x >= location)){
                                    lowShark.x = location;
                                    lowShark.size = s.size;
                                }
                            }
                            

                        }else { // if(s.dir == 2 || s.dir == 3)
                            // 위치 계산
                            int location;
                            if(s.dir == 2)
                                location = (k-s.speed) % (2*c -2);
                            else
                                location = (k+s.speed) % (2*c -2);

                            if(location < 0){
                                location = -location;
                                s.dir = 5-s.dir;
                            }
                            if(location >= c){
                                location = (2*c - 2) - location;
                                s.dir = 5-s.dir;
                            }
                            
                            if((nextMap[j][location] == null) || (nextMap[j][location].size < s.size)){
                                nextMap[j][location] = s;

                                // 바로 다음에 낚시할 곳이면 해당 열 제일 작은 x좌표 찾기.
                                if((location == i+1) && (lowShark.x >= j)){
                                    lowShark.x = j;
                                    lowShark.size = s.size;
                                }
                            }
                        }
                        nowMap[j][k] = null;
                    }
                }
            }
            
            isEven = !isEven;
        }

        System.out.print(ans);

        re.close();
    }
}

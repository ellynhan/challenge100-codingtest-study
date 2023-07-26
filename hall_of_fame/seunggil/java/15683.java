import java.io.*;
import java.util.*;

class Pos{
    int x;
    int y;
    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
}
public class Main {
    static final int[][] delta = {{1,0},{-1,0},{0,1},{0,-1}};
    static final int[][] cctv = {{0},{11,12,13,14},{21,22},{31,32,33,34},{41,42,43,44}, {51}};

    static ArrayList<Pos> cctvList = new ArrayList<>();
    static int[][] map;
    static int ans = 0;
    
    static int n;
    static int m;

    public static boolean init(int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }

    public static void combination(int index){
        if(index == cctvList.size()){
            cal();
        }else{
            int x = cctvList.get(index).x;
            int y = cctvList.get(index).y;
            int cctvType = map[x][y] / 10;
            for (int i = 0; i < cctv[cctvType].length; i++) {
                map[x][y] = cctv[cctvType][i];
                combination(index+1);
            }
        }
    }

    public static void cal(){
        boolean[][] visit = new boolean[n][m];

        for (Pos bs : cctvList) {
            int cctvType = map[bs.x][bs.y];

            if(cctvType / 10 == 1){
                int x = bs.x;
                int y = bs.y;
                int[] d;
                switch(cctvType % 10){
                    case 1:
                        d = delta[0];
                        break;
                    case 2:
                        d = delta[1];
                        break;
                    case 3:
                        d = delta[2];
                        break;
                    case 4:
                        d = delta[3];
                        break;
                    default:
                        d = delta[3];
                        break;
                }
                while(init(x, y) && map[x][y] != 6){
                    visit[x][y] = true;
                    x += d[0];
                    y += d[1];
                }
            }else if(cctvType / 10 == 2){
                if(cctvType % 10 == 1){
                    for (int i = 0; i < 2; i++) {
                        int x = bs.x;
                        int y = bs.y;
                        int[] d = delta[i];
                        visit[x][y] = true;

                        while(init(x, y) && map[x][y] != 6){
                            visit[x][y] = true;
                            x += d[0];
                            y += d[1];
                        }
                    }
                }else{
                    for (int i = 2; i < 4; i++) {
                        int x = bs.x;
                        int y = bs.y;
                        int[] d = delta[i];
                        visit[x][y] = true;

                        while(init(x, y) && map[x][y] != 6){
                            visit[x][y] = true;
                            x += d[0];
                            y += d[1];
                        }
                    }
                }
            }else if(cctvType / 10 == 3){
                if(cctvType % 10 == 1){
                    int x = bs.x;
                    int y = bs.y;
                    int[] d = delta[1];
                    visit[x][y] = true;

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }

                    x = bs.x;
                    y = bs.y;
                    d = delta[2];
                    visit[x][y] = true;

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }

                }else if(cctvType % 10 == 2){
                    int x = bs.x;
                    int y = bs.y;
                    int[] d = delta[1];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }

                    x = bs.x;
                    y = bs.y;
                    d = delta[3];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }
                }else if(cctvType % 10 == 3){
                    int x = bs.x;
                    int y = bs.y;
                    int[] d = delta[0];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }

                    x = bs.x;
                    y = bs.y;
                    d = delta[3];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }
                }else{
                    int x = bs.x;
                    int y = bs.y;
                    int[] d = delta[0];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }

                    x = bs.x;
                    y = bs.y;
                    d = delta[2];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }
                }
            }else if(cctvType / 10 == 4){
                int d;
                switch(cctvType % 10){
                    case 1:
                        d = 0;
                        break;
                    case 2:
                        d = 1;
                        break;
                    case 3:
                        d = 2;
                        break;
                    case 4:
                        d = 3;
                        break;
                    default:
                        d = 4;
                        break;
                }

                for (int i = 0; i < 4; i++) {
                    if(i == d)
                        continue;
                    int x = bs.x;
                    int y = bs.y;
                    int[] t = delta[i];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += t[0];
                        y += t[1];
                    }
                }

            }else if(cctvType / 10 == 5){
                for (int i = 0; i < 4; i++) {
                    int x = bs.x;
                    int y = bs.y;
                    int[] d = delta[i];

                    while(init(x, y) && map[x][y] != 6){
                        visit[x][y] = true;
                        x += d[0];
                        y += d[1];
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visit[i][j] && map[i][j] == 0)
                    result++;
            }
        }

        ans = Integer.min(ans, result);

    }

    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        String[] s = re.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);

        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            StringTokenizer token = new StringTokenizer(re.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(token.nextToken());
                if(map[i][j] == 0)
                    ans++;
                else if(map[i][j] != 6){
                    map[i][j] = map[i][j] * 10 + 1;
                    cctvList.add(new Pos(i,j));
                }
            }
        }
        combination(0);

        System.out.println(ans);

        re.close();
    }
}

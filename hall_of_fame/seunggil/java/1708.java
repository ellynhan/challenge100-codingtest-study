import java.util.*;
import java.io.*;

class Pos{
    Long x;
    Long y;

    public Pos(Long x, Long y) {
        this.x = x;
        this.y = y;
    }
}

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(re.readLine());

        Pos[] inputData = new Pos[n+1];
        for(int i = 0; i < n; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            long x = Long.parseLong(token.nextToken());
            long y = Long.parseLong(token.nextToken());
            
            inputData[i] = new Pos(x,y);
        }

        Arrays.sort(inputData, 0, n, (a,b)->{
            if(a.y == b.y)
                return Long.compare(a.x, b.x);
            else
                return Long.compare(a.y, b.y);
        });

        Pos start = inputData[0];
        inputData[n] = inputData[0];

        Arrays.sort(inputData, 1, n, 
            (a,b)->{
                Long v1X = a.x - start.x;
                Long v1Y = a.y - start.y;

                Long v2X = b.x - start.x;
                Long v2Y = b.y - start.y;

                Long result = v1X * v2Y - v2X * v1Y;
                if(result == 0){
                    return Long.compare((v1X*v1X + v1Y*v1Y), (v2X*v2X + v2Y*v2Y));
                }else{
                    return Long.compare(0,result);
                }
        });

        Stack<Pos> GrahamScan = new Stack<>();
        GrahamScan.add(start);

        for(int i = 1; i < n+1; i++){
            if(GrahamScan.size() < 2){
                GrahamScan.add(inputData[i]);
            }else{
                while(true){
                    Pos prev = GrahamScan.pop();
                    Pos pprev = GrahamScan.peek();

                    // ab, bc 벡터 구하기.
                    long[] ab = new long[]{prev.x - pprev.x, prev.y - pprev.y};
                    long[] bc = new long[]{inputData[i].x - prev.x, inputData[i].y - prev.y};

                    // 반시계면 => 새로 추가하고 끝.
                    if(ab[0] * bc[1] - ab[1] * bc[0] > 0){
                        GrahamScan.add(prev);
                        GrahamScan.add(inputData[i]);
                        break;
                    }else if(GrahamScan.size() < 2){
                        GrahamScan.add(inputData[i]);
                        break;
                    }
                }
            }
        }

        System.out.print(GrahamScan.size()-1);
        re.close();
    }
}
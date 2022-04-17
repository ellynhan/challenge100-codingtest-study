import java.util.*;
import java.io.*;

class Pos{
    double x;
    double y;

    public Pos(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getTime(Pos other, boolean isCannon){
        double xlen = other.x - x;
        double ylen = other.y - y;

        if(isCannon){
            double distance = Math.sqrt(Math.pow(xlen,2)+Math.pow(ylen,2));
            return Double.min(2 + Math.abs(50-distance)/5, distance/5);
        }else{
            return Math.sqrt(Math.pow(xlen,2)+Math.pow(ylen,2)) / 5.0;
        }
        
    }

}
public class _BOJ_SP_G2_10473 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer token = new StringTokenizer(re.readLine());
        Pos start = new Pos(Double.parseDouble(token.nextToken()), Double.parseDouble(token.nextToken()));
        token = new StringTokenizer(re.readLine());
        Pos end = new Pos(Double.parseDouble(token.nextToken()), Double.parseDouble(token.nextToken()));

        int n = Integer.parseInt(re.readLine());

        Pos[] inputData = new Pos[n+2];
        inputData[0] = start;
        inputData[n+1] = end;
        for(int i = 1; i < n+1; i++){
            token = new StringTokenizer(re.readLine());
            inputData[i] = new Pos(Double.parseDouble(token.nextToken()), Double.parseDouble(token.nextToken()));
        }
        double[] distance = new double[n+2];
        boolean[] checked = new boolean[n+2];

        checked[0] = true;

        for(int i = 1; i < n+2; i++){
            distance[i] = start.getTime(inputData[i], false);
        }
        for(int i = 0; i < n+1; i++){
            int select = -1;

            // 가장 가까운 점 선택.
            for(int j = 1; j < n+2; j++){
                if(!checked[j]){
                    if(select == -1 || distance[j] < distance[select])
                        select = j;
                }
            }

            // 도착지이면 => 답 출력
            if(select == n+1){
                System.out.println(distance[select]);
                break;
            }else{
                // 대포면 => 거리 갱신.
                checked[select] = true;
                for(int j = 1; j < n+2; j++){
                    if(checked[j])
                        continue;
                    distance[j] = Double.min(distance[j], inputData[select].getTime(inputData[j], true) + distance[select]);
                }
            }
        }
        re.close();
    }
}

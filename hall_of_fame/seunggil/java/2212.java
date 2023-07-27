import java.util.*;
import java.io.*;

public class _BOJ_Greedy_G5_2212 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        int sensorCnt = Integer.parseInt(re.readLine());
        int receiverCnt = Integer.parseInt(re.readLine());

        // 중복되지 않고, 정렬되게.        
        TreeSet<Integer> sensors = new TreeSet<>();
        
        StringTokenizer token = new StringTokenizer(re.readLine());
        re.close();

        for(int i = 0; i < sensorCnt; i++){
            int n = Integer.parseInt(token.nextToken());
            sensors.add(n);
        }

        // 이전 센서와의 거리
        ArrayList<Integer> cumul = new ArrayList<>(sensors.size()+1);

        Integer before = sensors.first();
        Iterator<Integer> iter = sensors.iterator();

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        while(iter.hasNext()){
            int n = iter.next();
            cumul.add(n-before);
            pq.add(n-before);
            before = n;
        }


        int answer = 0;
        int nowSize = pq.size();
        // 처음에 들어간 0은 빼자.
        pq.poll();

        // 집중국 수가 맞춰질때까지.
        while(receiverCnt < nowSize){
            answer += pq.poll();
            nowSize--;
        }
    
        System.out.print(answer);
    }
}

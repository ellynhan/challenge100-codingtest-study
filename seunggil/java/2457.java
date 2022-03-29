import java.util.*;
import java.io.*;

class Date{
    int start;
    int end;

    public Date(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class _BOJ_Greedy_G3_2457 {
    public static void main(String[] args) throws IOException {
        final int[] day = new int[]{0,0,31,59,90,120,151,181,212,243,273,304,334};
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(re.readLine());
        Date[] inputData = new Date[n];
        for(int i = 0; i < n; i++){
            StringTokenizer token = new StringTokenizer(re.readLine());
            int start = day[Integer.parseInt(token.nextToken())]+ Integer.parseInt(token.nextToken());
            int end = day[Integer.parseInt(token.nextToken())] + Integer.parseInt(token.nextToken());

            if(start <= day[3])
                start = day[3]+1;
            if(end > day[12])
                end = day[12]+1;
            inputData[i] = new Date(start, end);
        }

        Arrays.sort(inputData, (a,b)->{
            return Integer.compare(b.end, a.end);
        });

        Stack<Date> out = new Stack<>();
        ArrayDeque<Date> deque = new ArrayDeque<>(Arrays.asList(inputData));
        
        int answer = 0;
        // 초기 값 3월 1일부터 꽃이 없다.
        int nowDay = day[3]+1;

        while(nowDay <= day[12] && !deque.isEmpty()){
            Date now = deque.pollFirst();
            if(now.start <= nowDay){
                answer++;
                nowDay = now.end;
                while(!out.empty()){
                    Date before = out.pop();
                    if(before.end > nowDay)
                        deque.addFirst(before);
                }
            }else{
                out.add(now);
            }
        }
        
        if(nowDay <= day[12])
            System.out.print(0);
        else
            System.out.print(answer);

        re.close();
    }
}

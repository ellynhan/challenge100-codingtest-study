import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());

        int n = Integer.parseInt(br.readLine()), t;
        Optional<Integer> tmp;

        for(int i = 0; i < n; i++) {
            t = Integer.parseInt(br.readLine());
            priorityQueue.add(t);

            if(t == 0) {
                tmp = Optional.ofNullable(priorityQueue.poll());

                if(tmp == null) System.out.println(0);
                else System.out.println(tmp.get());
            }
        }
    }

}
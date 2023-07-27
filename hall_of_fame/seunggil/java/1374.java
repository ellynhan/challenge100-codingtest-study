import java.util.*;
import java.io.*;

public class _BOJ_DC_G4_1374 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<Integer> inputData = new LinkedList<>();
        ArrayList<Integer> sortedInputData = new ArrayList<>();
        int n = Integer.parseInt(re.readLine());

        for(int i = 0; i < n; i++){
            Integer num = Integer.parseInt(re.readLine());
            if(num != inputData.peekLast()){
                inputData.add(num);
                sortedInputData.add(num);
            }
        }

        sortedInputData.sort(null);

        long answer = 0;
        for(int idx = 0; idx < sortedInputData.size() - 1; idx++){
            int i = sortedInputData.get(idx);
            ListIterator<Integer> iter = inputData.listIterator();
            while(i != iter.next());
            int a = Integer.MAX_VALUE, b = Integer.MAX_VALUE;

            if(iter.hasNext()){
                a = iter.next();
                iter.previous();
            }
            iter.previous();

            if(iter.hasPrevious()){
                b = iter.previous();
                iter.next();
            }
            iter.next();

            if(Math.min(a,b) != Integer.MAX_VALUE){
                answer += Math.abs(i - Math.min(a,b));
            }
            iter.remove();
        }

        System.out.print(answer);

        re.close();
    }
}

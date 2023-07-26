import java.util.*;
import java.util.Map.Entry;
import java.io.*;

class Gem{
    int weight;
    int value;

    public Gem(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
}
public class _BOJ_Greedy_G2_1202 {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());

        int n = Integer.parseInt(token.nextToken());
        int k = Integer.parseInt(token.nextToken());

        Gem[] inputData = new Gem[n];
        for(int i = 0; i < n; i++){
            token = new StringTokenizer(re.readLine());
            inputData[i] = new Gem(Integer.parseInt(token.nextToken()), Integer.parseInt(token.nextToken()));
        }

        Arrays.sort(inputData, (a, b)->{
            return Integer.compare(b.value, a.value);
        });
        
        TreeMap<Integer,Integer> bags = new TreeMap<>();
        for(int i = 0; i < k; i++){
            int target = Integer.parseInt(re.readLine());
            bags.put(target, bags.getOrDefault(target, 0)+1);
        }

        long answer = 0;
        for(Gem iter : inputData){
            Entry<Integer, Integer> targetBag = bags.ceilingEntry(iter.weight);

            if(targetBag != null && targetBag.getValue() != 0){
                if(targetBag.getValue() == 1){
                    bags.remove(targetBag.getKey());
                }else{
                    bags.put(targetBag.getKey(), targetBag.getValue()-1);
                }
                answer += iter.value;
            }
            
        }
        System.out.print(answer);
        re.close();
    }
}

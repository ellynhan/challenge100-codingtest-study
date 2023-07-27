import java.util.*;
import java.io.*;

public class Main{
    static class Node{
        int count = 0;
        List<Integer> tree = new ArrayList<>();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer(re.readLine());
        int peopleCnt = Integer.parseInt(token.nextToken());
        int relationCnt = Integer.parseInt(token.nextToken());

        Node[] inputData = new Node[peopleCnt];

        for(int i = 0; i < peopleCnt; i++){
            inputData[i] = new Node();
        }
        for(int i = 0; i < relationCnt; i++){
            token = new StringTokenizer(re.readLine());
            int from = Integer.parseInt(token.nextToken()) - 1;
            int to =  Integer.parseInt(token.nextToken()) - 1;

            inputData[from].count++;
            inputData[to].tree.add(from);
        }

        Stack<Integer> stack = new Stack<>(); 
        for(int i = 0; i < peopleCnt; i++){
            if(inputData[i].count == 0){
                stack.add(i);
            }
        }

        int ans = 0;
        while(!stack.isEmpty()){
            int now = stack.pop();
            ans++;

            for(int i = 0, n = inputData[now].tree.size(); i < n; i++){
                int next = inputData[now].tree.get(i);
                if(--inputData[next].count == 0){
                    stack.add(next);
                }
            }
        }

        System.out.print(ans);
        re.close();
    }
}
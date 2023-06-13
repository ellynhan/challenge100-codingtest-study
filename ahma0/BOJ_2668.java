import java.io.*;
import java.util.*;

public class Main {
    static PriorityQueue<Integer> answer;
    static boolean[] visited;
    static int[] arr;
    static int num = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        visited = new boolean[N + 1];
        answer = new PriorityQueue<>();
        arr = new int[N + 1];

        for(int i = 1; i < arr.length; i++)
            arr[i] = Integer.parseInt(br.readLine());

        for(int i = 1; i < N + 1; i++){
            visited[i] = true;
            num = i;
            dfs(i);
            visited[i] = false;
        }

        sb.append(answer.size()).append("\n");

        for(Integer i : answer)
            sb.append(i).append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

    static void dfs(int v) {
        if(num == arr[v]) answer.add(num);

        if(!visited[arr[v]]) {
            visited[arr[v]] = true;
            dfs(arr[v]);
            visited[arr[v]] = false;
        }

    }
}

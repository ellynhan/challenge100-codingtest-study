import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        LinkedList<Integer> list = new LinkedList<>();

        for(int i = 0; i < N; i++)
            list.add(Integer.parseInt(br.readLine()));

        Collections.sort(list);

        for(Integer i : list)
            sb.append(i + "\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}

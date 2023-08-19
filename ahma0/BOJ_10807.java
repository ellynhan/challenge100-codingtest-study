import java.io.*;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        LinkedHashMap<Integer, Integer> list = new LinkedHashMap<>();

        for(int i = 0; i < N; i++) {
            int t = Integer.parseInt(st.nextToken());
            if(!list.containsKey(t))
                list.put(t, 1);
            else list.replace(t, list.get(t) + 1);
        }

        int v = Integer.parseInt(br.readLine());

        if(list.containsKey(v))
            sb.append(list.get(v)).append("\n");
        else
            sb.append(0).append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}


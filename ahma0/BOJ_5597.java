import java.io.*;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        TreeSet<Integer> set = new TreeSet<>();

        for(int i = 0; i < 28; i++)
            set.add(Integer.parseInt(br.readLine()));

        for(int i = 1; i <= 30; i++) {
            if(!set.contains(i))
                sb.append(i).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int alpha[] = new int[26];
        int cnt = 9;

        for(int i = 0; i < N; i++) {
            String str = br.readLine();

            for(int j = 0; j < str.length(); j++) {
                char c = str.charAt(j);
                alpha[c - 'A'] += (int) Math.pow(10, str.length() - 1 - j);
            }
        }

        Arrays.sort(alpha);

        int sum = 0;
        int index = 25;
        while(alpha[index] != 0) {
            sum += alpha[index] * cnt;
            cnt --;
            index--;
        }

        sb.append(sum).append("\n");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }


}
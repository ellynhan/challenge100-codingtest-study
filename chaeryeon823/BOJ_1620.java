import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * [BOJ] 1620 / 나는야 포켓몬 마스터 이다솜 / 실버4
 */
public class BOJ_1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, String> hashMap = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            hashMap.put(tmp, String.valueOf(i + 1));
            hashMap.put(String.valueOf(i + 1), tmp);
        }
        for (int i = 0; i < M; i++) {
            String tmp = br.readLine();
            bw.write(hashMap.get(tmp)+"\n");
        }

        bw.flush();
        bw.close();
        br.close();


    }
}

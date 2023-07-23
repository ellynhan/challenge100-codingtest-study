import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * [BOJ] 17219 / 비밀번호 찾기 / 실버4
 */
public class BOJ_17219 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, String> hashMap = new HashMap<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            hashMap.put(st.nextToken(), st.nextToken());
        }

        for (int i = 0; i < M; i++) {
            String tmp = br.readLine();
            bw.write(hashMap.get(tmp) + "\n");
        }

        bw.flush();
        bw.close();
        br.close();

    }
}

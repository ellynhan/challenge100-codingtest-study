import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * [BOJ] 9375 / 패션왕 신해빈 / 실버3
 */
public class BOJ_9375 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            HashMap<String, Integer> hashMap = new HashMap<>();
            int answer=1;
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                String tmp = st.nextToken();
                tmp = st.nextToken();

                if (hashMap.containsKey(tmp)) {
                    hashMap.put(tmp, hashMap.getOrDefault(tmp, 0) + 1);
                } else {
                    hashMap.put(tmp, 1);
                }

            }
            for(int k : hashMap.values()) {
                answer*=(k+1);
            }
            bw.write((answer-1)+"\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

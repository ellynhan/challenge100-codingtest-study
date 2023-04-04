import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()), t = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());

        HashMap<Integer, Integer> map = new HashMap();

        for(int i = 0; i < N; i++) {
            t = Integer.parseInt(st.nextToken());

            if(!map.containsKey(t)) map.put(t, 1);
            else map.put(t, map.get(t) + 1);
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < M; i++) {
            t = Integer.parseInt(st.nextToken());

            if(!map.containsKey(t)) sb.append(0 + " ");
            else sb.append(map.get(t) + " ");
        }

        sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb);

    }

}
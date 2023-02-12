import java.io.*;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

class BOJ_1620 {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        LinkedHashMap<String, Integer> map = new LinkedHashMap<>();
        ArrayList<String> arr = new ArrayList();
        String t;

        for(int i = 0; i < n; i++) {
            arr.add(br.readLine());
            map.put(arr.get(i), i + 1);
        }

        for(int i = 0; i < m; i++) {
            t = br.readLine();

            if(Character.isDigit(t.charAt(0)))
                bw.write(arr.get(Integer.parseInt(t) - 1) + "\n");
            else
                bw.write(map.get(t) + "\n");
        }

        bw.flush();
        bw.close();

    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<String> arrayList = new ArrayList<>();
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), cnt = 0;
        String t = "";

        for(int i = 0; i < n; i++)
            arrayList.add(br.readLine());

        for(int i = 0; i < m; i++) {
            t = br.readLine();
            if(arrayList.contains(t)) cnt++;
        }

        System.out.println(cnt);
    }
}
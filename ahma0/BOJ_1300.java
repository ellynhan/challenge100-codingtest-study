import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        long low = 1;
        long high = K;

        while(low < high) {
            long mid = (low + high) / 2;
            long count = 0;

            for(int i = 1; i <= N; i++)
                count += Math.min(mid / i, N);

            if(K <= count)
                high = mid;
            else low = mid + 1;

        }

        sb.append(low).append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

}
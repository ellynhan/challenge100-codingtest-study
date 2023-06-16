import java.io.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        dfs(0, N);

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    static void dfs(int output, int n) {
        if(n == 0) {
            if(isPrime(output)) {
                sb.append(output).append("\n");
                return;
            }
        }

        for(int i = 0; i < 10; i++) {
            int next = output * 10 + i;
            if(isPrime(next))
                dfs(next, n - 1);
        }
    }

    static boolean isPrime(int n) {
        if(n < 2) return false;

        for(int i = 2; i <= Math.sqrt(n); i++)
            if(n % i == 0) return false;

        return true;
    }

}
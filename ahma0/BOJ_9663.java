import java.io.*;

public class Main {

    static int N, cnt, chess[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        chess = new int[N];

        search(0);

        System.out.println(cnt);

    }

    static void search(int n) {

        if(n == N) {
            cnt++;
            return;
        }

        for(int i = 0; i < N; i++) {
            chess[n] = i;

            if(isOK(n))
                search(n + 1);
        }

    }

    static boolean isOK(int col) {
        for(int i = 0; i < col; i++) {
            if(chess[i] == chess[col])
                return false;

            if(col - i == Math.abs(chess[col] - chess[i]))
                return false;
        }

        return true;
    }

}

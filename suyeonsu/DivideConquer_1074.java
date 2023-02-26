import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int N, r, c;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        visit(0, 0, (int)Math.pow(2, N), 0);
        System.out.println(answer);
    }

		private static void visit(int x, int y, int size, int num) {
        if(x == r && y == c) {
            answer = num;
            return;
        }
        int n = size/2;
        if(x <= r && y <= c && c < y+n) visit(x, y, n, num);
        if(x <= r && r < x+n && y+n <= c && c < y+size) visit(x, y+n, n, num + n*n*1);
        if(x+n <= r && r < x+size && y <= c && c < y+size) visit(x+n, y, n, num + n*n*2);
        if(x+n <= r && r < x+size && y+n <= c && c < y+size) visit(x+n, y+n, n, num + n*n*3);
    }

}

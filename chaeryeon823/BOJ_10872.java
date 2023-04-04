import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_10872 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int num=Integer.parseInt(br.readLine());
        System.out.println(factorial(num));
    }

    public static int factorial(int n) {
        if(n<=1) {
            return 1;
        }
        return n*factorial(n-1);
    }
}

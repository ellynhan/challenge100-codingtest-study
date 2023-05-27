import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        if(n == 4) {
            System.out.println(2);
            return;
        }
        if(n == 1 || (n > 2 && n < 5)) {
            System.out.println(-1);
            return;
        }

        if(n % 5 == 0) System.out.println(n / 5);
        else if(n % 5 == 2) System.out.println(n / 5 + 1);
        else if(n % 5 == 3) System.out.println(n / 5 + 3);
        else if(n % 5 == 1 || n % 5 == 4) System.out.println(n / 5 + 2);
    }

}

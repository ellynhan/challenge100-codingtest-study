import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            String s = br.readLine();

            System.out.println(s.charAt(0) + "" + s.charAt(s.length() - 1));
        }

    }

}

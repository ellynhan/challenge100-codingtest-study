import java.io.*;

public class Main {
    //05:13 ~ 05:34

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringBuffer S = new StringBuffer(br.readLine());
        StringBuffer T = new StringBuffer(br.readLine());

        while(S.length() < T.length()) {
            if(T.charAt(T.length() - 1) == 'A')
                T.deleteCharAt(T.length() - 1);
            else {
                T.deleteCharAt(T.length() - 1);
                T.reverse();
            }
        }

        if (S.toString().equals(T.toString()))
            sb.append(1).append("\n");
        else sb.append(0).append("\n");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}


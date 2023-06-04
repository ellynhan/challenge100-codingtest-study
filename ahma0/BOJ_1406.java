import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String s = br.readLine();

        Stack<String> left = new Stack<>();
        Stack<String> right = new Stack<>();

        for(int i = 0; i < s.length(); i++)
            left.push(String.valueOf(s.charAt(i)));

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();

            switch (temp) {
                case "P":
                    left.push(st.nextToken());
                    break;
                case "L":
                    if(!left.isEmpty())
                        right.push(left.pop());
                    break;
                case "D":
                    if(!right.isEmpty())
                        left.push(right.pop());
                    break;
                case "B":
                    if(!left.isEmpty())
                        left.pop();
                    break;
            }
        }

        while(!left.isEmpty())
            right.push(left.pop());

        while(!right.isEmpty())
            sb.append(right.pop() + "");

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();

    }

}

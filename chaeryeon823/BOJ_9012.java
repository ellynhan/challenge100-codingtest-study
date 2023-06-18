import java.io.*;
import java.util.Stack;

/**
 * [BOJ] 9012 / 괄호 / 실버4
 */
public class BOJ_9012 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        //문자열의 개수
        int N = Integer.parseInt(br.readLine());

        //스택
        Stack<Character> stack = new Stack<>();

        boolean check=true;

        for (int p = 0; p < N; p++) {
            String ps = br.readLine();
            for (int i = 0; i < ps.length(); i++) {
                // ( 일때 넣어주고
                if(ps.charAt(i)=='(') {
                    stack.push('(');
                }
                // ) 일떄
                else {
                    // stack이 비어있으면 check false로 바꾸고 멈추기 -> )가 더 많다.
                    if(stack.isEmpty()) {
                        check=false;
                        break;
                    }
                    // 비어있지 않으면, ( 빼기
                    else {
                        stack.pop();
                    }
                }

            }
            if(!stack.isEmpty()) {
                check=false;
            }

            if(check) {
                bw.write("YES\n");
            }
            else {
                bw.write("NO\n");
            }
            stack.clear();
            check=true;
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

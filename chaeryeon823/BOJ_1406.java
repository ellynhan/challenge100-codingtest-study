import java.io.*;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.StringTokenizer;

/**
 * [BOJ] 1406 / 에디터 / 실버2
 */

public class BOJ_1406 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        String str = br.readLine();
        LinkedList<Character> list = new LinkedList<>();
        ListIterator<Character> iter=list.listIterator();

        for (int i = 0; i < str.length(); i++) {
            iter.add(str.charAt(i));
        }


        // 명령어의 개수
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String op = st.nextToken();

            if (op.equals("L")) {
                if (iter.hasPrevious()) {
                    iter.previous();
                }
            }

            if (op.equals("D")) {
                if (iter.hasNext()) {
                    iter.next();
                }
            }

            if (op.equals("B")) {
                if (iter.hasPrevious()) {
                    iter.previous();
                    iter.remove();
                }
            }

            if (op.equals("P")) {
                char tmp = st.nextToken().charAt(0);
                iter.add(tmp);
            }
        }

        for (Character character : list) {
            bw.write(character);
        }

        bw.flush();
        bw.close();
        br.close();

    }
}

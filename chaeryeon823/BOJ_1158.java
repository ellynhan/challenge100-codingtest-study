import javax.management.Query;
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * [BOJ] 1158 / 요세푸스 문제 / 실버4
 */
public class BOJ_1158 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;

        Queue<Integer> queue = new LinkedList<>();

        int check = 1;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            queue.add(i);
        }
        while (!queue.isEmpty()) {
            int tmp = queue.poll();
            if (check == K) {
                arr.add(tmp);
                check = 1;
            } else {
                queue.add(tmp);
                check++;
            }
        }
        System.out.print("<");
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size() - 1) {
                System.out.print(arr.get(i) + ">");
            } else {
                System.out.print(arr.get(i) + ", ");
            }
        }

    }
}

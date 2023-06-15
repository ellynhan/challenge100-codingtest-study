import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

/**
 * [BOJ] 5430 / AC / 골드5
 */
public class BOJ_5430 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            boolean direction = true;
            boolean isError = false;
            //명령어 받아오기
            String p = br.readLine();
            //배열 크기 받아오기
            int N = Integer.parseInt(br.readLine());
            //배열 받아오기
            String tmp = br.readLine();
            Deque<Integer> deque = new LinkedList<>();

            //배열에 저장
            tmp=tmp.substring(1,tmp.length()-1);
            st=new StringTokenizer(tmp, ",");
            for (int i = 0; i < N; i++) {
                deque.add(Integer.parseInt(st.nextToken()));
            }

            //명령어 계산
            for (int i = 0; i < p.length(); i++) {
                //R인 경우
                if (p.charAt(i) == 'R') {
                    direction = !direction;

                }
                //D인 경우
                else {
                    if (direction) {
                        if (deque.isEmpty()) {
                            bw.write("error\n");
                            isError = true;
                            break;
                        }
                        deque.pollFirst();
                    } else {
                        if (deque.isEmpty()) {
                            bw.write("error\n");
                            isError = true;
                            break;
                        }
                        deque.pollLast();
                    }
                }
            }

            //에러가 난 경우, 배열 출력하지 않고 넘어감.
            if (!isError) {
                bw.write("[");
                int size=deque.size();
                if(direction) {
                    for (int i = 0; i < size; i++) {
                        if (i == (size - 1)) {
                            bw.write(String.valueOf(deque.pollFirst()));
                        } else {
                            bw.write(deque.pollFirst() + ",");

                        }
                    }
                    bw.write("]\n");
                }
                else {
                    for (int i = 0; i < size; i++) {
                        if (i == (size - 1)) {
                            bw.write(String.valueOf(deque.pollLast()));
                        } else {
                            bw.write(deque.pollLast() + ",");

                        }
                    }
                    bw.write("]\n");
                }

            }
        }


        bw.flush();
        bw.close();
        br.close();
    }
}

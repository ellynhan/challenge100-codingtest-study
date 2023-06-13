import java.io.*;
import java.util.*;

public class Main {
    // 02:27 ~ 02:48

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Lecture[] lectures = new Lecture[N];

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            lectures[i] = new Lecture(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(lectures);

        pq.offer(lectures[0].end);

        for(int i = 1; i < N; i++) {
            if(pq.peek() <= lectures[i].start)
                pq.poll();
            pq.offer(lectures[i].end);
        }

        bw.write(pq.size() + "\n");
        bw.flush();
        bw.close();
        br.close();

    }

    static class Lecture implements Comparable<Lecture> {
        int start;
        int end;

        public Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture o) {
            if(this.start == o.start)
                return this.end - o.end;
            return this.start - o.start;
        }
    }

}
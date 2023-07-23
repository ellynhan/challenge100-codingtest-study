import java.io.*;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        PriorityQueue<Nums> pq = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            int t = Integer.parseInt(br.readLine());

            if(t == 0) {
                if(pq.isEmpty())
                    sb.append(0).append("\n");
                else
                    sb.append(pq.poll().num2).append("\n");
                continue;
            }

            pq.add(new Nums(Math.abs(t), t));
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    static class Nums implements Comparable<Nums> {
        int num;        //절대값
        int num2;       //원본

        public Nums(int num, int num2) {
            this.num = num;
            this.num2 = num2;
        }

        @Override
        public int compareTo(Nums o) {
            if(o.num == this.num)
                return this.num2 - o.num2;
            return this.num - o.num;
        }
    }

}
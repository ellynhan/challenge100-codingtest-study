import java.io.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static int tree[] = new int[10001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String t = "";

        int i = 0;
        while((t = br.readLine()) != null && !t.isEmpty())
            tree[i++] = Integer.parseInt(t);

        postOrder(0, i - 1);

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    static void postOrder(int n, int end) {
        if(n > end)
            return;

        int mid = n + 1;
        while(mid <= end && tree[mid] < tree[n])
            mid++;

        postOrder(n + 1, mid - 1);
        postOrder(mid, end);
        sb.append(tree[n]).append("\n");
    }

}
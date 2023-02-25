import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[] sel;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		sel = new int[m];
		combinations_with_replacement(0, 1);
		System.out.println(sb);
	}

	private static void combinations_with_replacement(int cnt, int num) {
		if(cnt == m) {
			for(int e : sel) sb.append(e + " ");
			sb.append("\n");
			return;
		}
		for(int i=num; i<=n; i++) {
			sel[cnt] = i;
			combinations_with_replacement(cnt+1, i);
		}
	}

}

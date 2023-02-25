import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[] sel;
	static StringBuilder answer = new StringBuilder();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		sel = new int[m];
		product(0);
		System.out.println(answer);
	}

	private static void product(int cnt) {
		if(cnt == m) {
			for(int e : sel) answer.append(e + " ");
			answer.append("\n");
			return;
		}
		for(int i=1; i<=n; i++) {
			sel[cnt] = i;
			product(cnt+1);
		}
	}

}

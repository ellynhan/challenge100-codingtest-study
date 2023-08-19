import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int M, N;

	void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());

		M = Integer.parseInt(tokenizer.nextToken());
		N = Integer.parseInt(tokenizer.nextToken());
	}

	void solve() throws IOException {
		boolean prime[] = new boolean[N+1];
		prime[0] = prime[1] = true;

		for (int i = 2; i <= Math.sqrt(N); ++i) {
			if (!prime[i]) {
				for(int j = i*i; j <= N; j += i) {
					prime[j] = true;
				}
			}
		}

		for (int i = M; i <= N; ++i) {
			if (!prime[i]) {
				writer.write(Integer.toString(i));
				writer.newLine();
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

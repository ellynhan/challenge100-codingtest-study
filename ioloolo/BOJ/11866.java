import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N, K;

	void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(tokenizer.nextToken());
		K = Integer.parseInt(tokenizer.nextToken());
	}

	void solve() throws IOException {
		Queue<Integer> q = new LinkedList<>() {{
			for (int i = 1; i <= N; ++i) {
				add(i);
			}
		}};

		writer.write("<");
		while (q.size() > 0) {
			for (int i = 0; i < K - 1; i++) {
				q.offer(q.poll());
			}

			writer.write(Integer.toString(q.poll()));

			if (q.size() > 0) {
				writer.write(", ");
			}
		}
		writer.write(">");
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	void solve() throws IOException {
		Map<Integer, Boolean> map = new LinkedHashMap<>();

		int N = Integer.parseInt(reader.readLine());
		tokenizer = new StringTokenizer(reader.readLine());
		for (int i = 0; i < N; ++i) {
			map.put(Integer.parseInt(tokenizer.nextToken()), true);
		}

		int M = Integer.parseInt(reader.readLine());
		tokenizer = new StringTokenizer(reader.readLine());
		for (int i = 0; i < M; ++i) {
			int n = Integer.parseInt(tokenizer.nextToken());

			writer.write(map.getOrDefault(n, false) ? "1" : "0");
			writer.newLine();
		}
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		// main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

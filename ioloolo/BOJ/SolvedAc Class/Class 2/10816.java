import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N, M;
	List<Integer> list1 = new LinkedList<>();
	List<Integer> list2 = new LinkedList<>();

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());
		tokenizer = new StringTokenizer(reader.readLine());
		for (int i = 0; i < N; ++i) {
			list1.add(Integer.parseInt(tokenizer.nextToken()));
		}

		M = Integer.parseInt(reader.readLine());
		tokenizer = new StringTokenizer(reader.readLine());
		for (int i = 0; i < M; ++i) {
			list2.add(Integer.parseInt(tokenizer.nextToken()));
		}
	}

	void solve() throws IOException {
		Map<Integer, Integer> called = new LinkedHashMap<>();

		for (int n : list1) {
			called.put(n, called.getOrDefault(n, 0)+1);
		}

		for (int n : list2) {
			writer.write(Integer.toString(called.getOrDefault(n, 0)) + " ");
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

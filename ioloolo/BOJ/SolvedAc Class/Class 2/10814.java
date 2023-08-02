import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N;
	Info[] arr;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new Info[N];

		for (int i = 0; i < N; ++i) {
			tokenizer = new StringTokenizer(reader.readLine());

			arr[i] = new Info();
			arr[i].age = Integer.parseInt(tokenizer.nextToken());
			arr[i].name = tokenizer.nextToken();
		}
	}

	void solve() throws IOException {
		Arrays.sort(arr, Comparator.comparingInt(o -> o.age));

		for (Info info : arr) {
			writer.write(String.format("%d %s", info.age, info.name));
			writer.newLine();
		}
	}

	static class Info {
		String name;
		int age;
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

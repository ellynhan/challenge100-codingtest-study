import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());
	}

	void solve() throws IOException {
		int cnt = 0;
		int num = 0;

		while (N > cnt) {
			cnt++;

			do {
				++num;
			} while (!Integer.toString(num).contains("666"));
		}

		writer.write(Integer.toString(num));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;
	LinkedList<Integer> list = new LinkedList<>();

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		while ((N--) > 0) {
			int n = Integer.parseInt(reader.readLine());

			if (n == 0) {
				list.pollLast();
			} else {
				list.add(n);
			}
		}
	}

	void solve() throws IOException {
		int sum = 0;

		for (int n : list) {
			sum += n;
		}

		writer.write(Integer.toString(sum));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

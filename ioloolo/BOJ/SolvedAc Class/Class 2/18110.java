import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;
	LinkedList<Integer> list = new LinkedList<>();

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		while ((N--) > 0) {
			list.add(Integer.parseInt(reader.readLine()));
		}
	}

	void solve() throws IOException {
		int skip = (int)Math.round(list.size() * 0.15);

		Collections.sort(list);

		for (int i = 0; i < skip; ++i) {
			list.pollFirst();
			list.pollLast();
		}

		int sum = 0;

		for (int n : list) {
			sum += n;
		}

		int avg = (int)Math.round((double) sum / list.size());

		writer.write(Integer.toString(avg));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

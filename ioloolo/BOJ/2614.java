import java.awt.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());
	}

	void solve() throws IOException {
		List<Integer> list = new LinkedList<>();

		for (int i = 1; i <= N; ++i) {
			list.add(i);
		}

		while (list.size() != 1) {
			list.remove(0);

			int top = list.get(0);

			list.remove(0);
			list.add(top);
		}

		writer.write(Integer.toString(list.get(0)));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

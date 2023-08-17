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

	int N;
	Info[] infos;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		infos = new Info[N];

		for (int i = 0; i < N; ++i) {
			tokenizer = new StringTokenizer(reader.readLine());

			infos[i] = new Info();
			infos[i].weight = Integer.parseInt(tokenizer.nextToken());
			infos[i].height = Integer.parseInt(tokenizer.nextToken());
		}
	}

	void solve() throws IOException {
		for (int i = 0; i < N; ++i) {
			int rank = 1;

			for (int j = 0; j < N; ++j) {
				if (i == j) continue;

				if (infos[i].weight < infos[j].weight && infos[i].height < infos[j].height) {
					rank++;
				}
			}

			writer.write(String.format("%d ", rank));
		}
	}

	static class Info {
		int height;
		int weight;
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

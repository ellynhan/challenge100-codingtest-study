import java.awt.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N;
	Point[] arr;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new Point[N];

		for (int i = 0; i < N; ++i) {
			tokenizer = new StringTokenizer(reader.readLine());

			arr[i] = new Point();
			arr[i].x = Integer.parseInt(tokenizer.nextToken());
			arr[i].y = Integer.parseInt(tokenizer.nextToken());
		}
	}

	void solve() throws IOException {
		Arrays.sort(arr, (o1, o2) -> {
			if (o1.x == o2.x) return o1.y - o2.y;
			return o1.x - o2.x;
		});

		for (Point point : arr) {
			writer.write(String.format("%d %d", point.x, point.y));
			writer.newLine();
		}
	}

	static class Point {
		int x, y;
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

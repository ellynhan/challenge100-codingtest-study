import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	PriorityQueue<Point> points = new PriorityQueue<>();

	void input() throws IOException {
		int T = Integer.parseInt(reader.readLine());

		while ((T--) > 0) {
			tokenizer = new StringTokenizer(reader.readLine());

			Point point = new Point();
			point.x = Integer.parseInt(tokenizer.nextToken());
			point.y = Integer.parseInt(tokenizer.nextToken());

			points.add(point);
		}
	}

	void solve() throws IOException {
		while (!points.isEmpty()) {
			Point point = points.poll();

			writer.write(String.format("%d %d", point.x, point.y));
			writer.newLine();
		}
	}

	static class Point implements Comparable<Point> {
		int x, y;

		@Override
		public int compareTo(Point o) {
			if (y == o.y) {
				return x - o.x;
			}

			return y - o.y;
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

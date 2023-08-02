import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static StringTokenizer tokenizer;

	static List<Triangle> list = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		while (true) {
			tokenizer = new StringTokenizer(reader.readLine());

			int a = Integer.parseInt(tokenizer.nextToken());
			int b = Integer.parseInt(tokenizer.nextToken());
			int c = Integer.parseInt(tokenizer.nextToken());

			if (a == 0 && b == 0 && c == 0) {
				break;
			}

			list.add(new Triangle(a, b, c));
		}
	}

	static void solve() throws IOException {
		for (Triangle triangle : list) {
			writer.write(triangle.isCorrect() ? "right" : "wrong");
			writer.newLine();
		}
	}

	static class Triangle {
		int a, b, c;

		Triangle(int a, int b, int c) {
			List<Integer> list = new ArrayList<>(List.of(a, b, c));
			Collections.sort(list);

			this.a = list.get(0);
			this.b = list.get(1);
			this.c = list.get(2);
		}

		boolean isCorrect() {
			return Math.pow(a, 2) + Math.pow(b, 2) == Math.pow(c, 2);
		}
	}
}

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static StringTokenizer tokenizer;

	static int N;
	static int K;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());

		N = Integer.parseInt(tokenizer.nextToken());
		K = Integer.parseInt(tokenizer.nextToken());
	}

	static void solve() throws IOException {
		int max = Integer.MIN_VALUE;

		for (int i = 1; i <= K; ++i) {
			max = Math.max(max, reverse(N * i));
		}

		writer.write(Integer.toString(max));
	}

	static int reverse(int n) {
		return Integer.parseInt(new StringBuilder(Integer.toString(n)).reverse().toString());
	}
}

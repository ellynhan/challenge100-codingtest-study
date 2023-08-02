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
		writer.write(Long.toString(factorial(N) / (factorial(K) * factorial(N-K))));
	}

	static long factorial(int n) {
		long result = 1;

		for (int i = 2; i <= n; ++i) {
			result *= i;
		}

		return result;
	}
}

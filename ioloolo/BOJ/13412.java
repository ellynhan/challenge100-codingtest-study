import java.io.*;
import java.math.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static int T;
	static int[] cases;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		T = Integer.parseInt(reader.readLine());

		cases = new int[T];

		for (int i = 0; i < T; ++i) {
			cases[i] = Integer.parseInt(reader.readLine());
		}
	}

	static void solve() throws IOException {
		for (int n : cases) {
			int cnt = 0;

			for (int a = 1; a <= Math.sqrt(n); ++a) {
				if ((double) n / a != (int) ((double) n / a)) continue;

				if (gcd(a, n/a) == 1 && lcm(a, n/a) == n) {
					cnt++;
				}
			}

			writer.write(Integer.toString(cnt));
			writer.newLine();
		}
	}

	static long gcd(int a, int b) {
		return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).longValue();
	}

	static long lcm(int a, int b) {
		return ((long) a *b) / gcd(a, b);
	}
}

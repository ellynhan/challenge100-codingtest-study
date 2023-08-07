import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());
	}

	void solve() throws IOException {
		BigInteger factorial = BigInteger.ONE;
		int cnt = 0;

		for (int i = 2; i <= N; ++i) {
			factorial = factorial.multiply(BigInteger.valueOf(i));
		}

		while (factorial.compareTo(BigInteger.ZERO) > 0) {
			if (factorial.remainder(BigInteger.TEN).compareTo(BigInteger.ZERO) == 0) cnt++;
			else break;

			factorial = factorial.divide(BigInteger.TEN);
		}

		writer.write(Integer.toString(cnt));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

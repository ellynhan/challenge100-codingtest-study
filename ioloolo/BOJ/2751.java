import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;
	int[] arr;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new int[N];

		for (int i = 0; i < N; ++i) {
			arr[i] = Integer.parseInt(reader.readLine());
		}
	}

	void solve() throws IOException {
		Arrays.sort(arr);

		for (int a : arr) {
			writer.write(Integer.toString(a));
			writer.newLine();
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

import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static int N;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new int[N];

		for (int i = 0; i < N; ++i) {
			arr[i] = Integer.parseInt(reader.readLine());
		}
	}

	static void solve() throws IOException {
		Arrays.sort(arr);

		for (int a : arr) {
			writer.write(Integer.toString(a));
			writer.newLine();
		}
	}
}

import java.io.*;
import java.time.LocalDate;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer tokenizer;

	static int K;
	static int L;
	static String[] str;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());
		K = Integer.parseInt(tokenizer.nextToken());
		L = Integer.parseInt(tokenizer.nextToken());

		str = new String[L];

		for (int i = 0; i < L; ++i) {
			str[i] = reader.readLine();
		}
	}

	static void solve() throws IOException {
		Set<String> set = new LinkedHashSet<>();

		for (String s : str) {
			set.remove(s);
			set.add(s);
		}

		int cnt = 0;
		for (String s : set) {
			writer.write(s);
			writer.newLine();

			if (++cnt == K) break;
		}
	}
}

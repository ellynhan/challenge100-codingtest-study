import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static List<Integer> list = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		while (true) {
			int n = Integer.parseInt(reader.readLine());

			if (n == 0) break;

			list.add(n);
		}
	}

	static void solve() throws IOException {
		for (int num : list) {
			String str = Integer.toString(num);

			String s1 = str.substring(0, (int)Math.ceil(str.length()/2.0));
			String s2 = str.substring((int)Math.floor(str.length()/2.0));

			writer.write(s1.equals(new StringBuilder(s2).reverse().toString()) ? "yes" : "no");
			writer.newLine();
		}
	}
}

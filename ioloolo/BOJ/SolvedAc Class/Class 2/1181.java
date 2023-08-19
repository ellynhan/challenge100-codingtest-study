import java.io.*;
import java.util.*;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;
	List<String> list = new LinkedList<>();

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		for (int i = 0; i < N; ++i) {
			String str = reader.readLine();

			if (!list.contains(str)) {
				list.add(str);
			}
		}
	}

	void solve() throws IOException {
		list.sort((str1, str2) -> str1.length() == str2.length()
			? str1.compareTo(str2)
			: str1.length() - str2.length());

		for (String str : list) {
			writer.write(str);
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

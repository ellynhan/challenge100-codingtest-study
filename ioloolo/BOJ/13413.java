import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static int T;
	static TestCase[] testCases;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		T = Integer.parseInt(reader.readLine());

		testCases = new TestCase[T];

		for (int i = 0; i < T; ++i) {
			testCases[i] = new TestCase();
			testCases[i].n = Integer.parseInt(reader.readLine());
			testCases[i].str1 = reader.readLine().toCharArray();
			testCases[i].str2 = reader.readLine().toCharArray();
		}
	}

	static void solve() throws IOException {
		for (TestCase testCase : testCases) {
			int cnt1 = 0;
			int cnt2 = 0;

			for (int i = 0; i < testCase.n; ++i) {
				if (testCase.str1[i] != testCase.str2[i]) {
					if (testCase.str1[i] == 'W') cnt1++;
					else cnt2++;
				}
			}

			writer.write(Integer.toString(Math.max(cnt1, cnt2)));
			writer.newLine();
		}
	}

	static class TestCase {
		public int n;
		public char[] str1;
		public char[] str2;
	}
}

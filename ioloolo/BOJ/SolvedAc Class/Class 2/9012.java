import java.awt.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	int N;
	String[] arr;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new String[N];

		for (int i = 0; i < N; ++i) {
			arr[i] = reader.readLine();
		}
	}

	void solve() throws IOException {
		for (String str : arr) {
			Stack<Character> stack = new Stack<>();
			boolean isExited = false;

			for (char c : str.toCharArray()) {
				if (c == '(') {
					stack.push('(');
				} else {
					if (stack.isEmpty()) {
						isExited = true;
						break;
					}

					stack.pop();
				}
			}

			writer.write(!isExited && stack.isEmpty() ? "YES" : "NO");
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

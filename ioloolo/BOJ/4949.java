import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	List<String> texts = new LinkedList<>();

	void input() throws IOException {
		String line;
		while (!(line = reader.readLine()).equals(".")) {
			texts.add(line);
		}
	}

	void solve() throws IOException {
		for (String text : texts) {
			Stack<Character> stack = new Stack<>();

			for (char c : text.toCharArray()) {
				if (c == '(' || c == '[') stack.push(c);

				if (c == ')') {
					if (!stack.isEmpty() && stack.peek() == '(') {
						stack.pop();
					} else {
						stack.push('A');
						break;
					}
				}

				if (c == ']') {
					if (!stack.isEmpty() && stack.peek() == '[') {
						stack.pop();
					} else {
						stack.push('A');
						break;
					}
				}
			}

			writer.write(stack.isEmpty() ? "yes" : "no");
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

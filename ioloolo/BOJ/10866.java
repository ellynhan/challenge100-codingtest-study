import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N;
	Operator[] arr;

	void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		arr = new Operator[N];

		for (int i = 0; i < N; ++i) {
			tokenizer = new StringTokenizer(reader.readLine());

			arr[i] = new Operator();
			arr[i].type = Operator.Type.valueOf(tokenizer.nextToken().toUpperCase());

			if (tokenizer.hasMoreTokens()) {
				arr[i].operand = Integer.parseInt(tokenizer.nextToken());
			}
		}
	}

	void solve() throws IOException {
		Deque<Integer> queue = new LinkedList<>();

		for (Operator operator : arr) {
			if (operator.type == Operator.Type.PUSH_FRONT) {
				queue.addFirst(operator.operand);
				continue;
			} else if (operator.type == Operator.Type.PUSH_BACK) {
				queue.addLast(operator.operand);
				continue;
			} else if (operator.type == Operator.Type.POP_FRONT) {
				if (queue.isEmpty()) {
					writer.write("-1");
				} else {
					writer.write(Integer.toString(queue.pollFirst()));
				}
			} else if (operator.type == Operator.Type.POP_BACK) {
				if (queue.isEmpty()) {
					writer.write("-1");
				} else {
					writer.write(Integer.toString(queue.pollLast()));
				}
			} else if (operator.type == Operator.Type.SIZE) {
				writer.write(Integer.toString(queue.size()));
			} else if (operator.type == Operator.Type.EMPTY) {
				writer.write(Integer.toString(queue.isEmpty() ? 1 : 0));
			} else if (operator.type == Operator.Type.FRONT) {
				if (queue.isEmpty()) {
					writer.write("-1");
				} else {
					writer.write(Integer.toString(queue.getFirst()));
				}
			} else if (operator.type == Operator.Type.BACK) {
				if (queue.isEmpty()) {
					writer.write("-1");
				} else {
					writer.write(Integer.toString(queue.getLast()));
				}
			}

			writer.newLine();
		}
	}

	static class Operator {
		public enum Type {
			PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK,
			SIZE, EMPTY, FRONT, BACK;
		}

		Type type;
		int operand;
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

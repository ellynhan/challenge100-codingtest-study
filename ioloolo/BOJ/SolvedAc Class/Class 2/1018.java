import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

// 35M

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

	int N, M;
	int[][] arr;

	int[] pattern1 = new int[]{0, 1, 0, 1, 0, 1, 0, 1};
	int[] pattern2 = new int[]{1, 0, 1, 0, 1, 0, 1, 0};

	void input() throws IOException {
		tokenizer = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(tokenizer.nextToken());
		M = Integer.parseInt(tokenizer.nextToken());

		arr = new int[N][M];

		for (int i = 0; i < N; ++i) {
			arr[i] = reader.readLine().chars().map(c -> c == 'W' ? 0 : 1).toArray();
		}
	}

	void solve() throws IOException {
		int answer = Integer.MAX_VALUE;

		for (int i = 0; i < N-8+1; ++i) {
			for (int j = 0; j < M-8+1; ++j) {
				int[][] cpy = Arrays.copyOfRange(arr, i, i + 8);

				for (int k = 0; k < cpy.length; ++k) {
					cpy[k] = Arrays.copyOfRange(cpy[k], j, j+8);
				}

				answer = Math.min(answer, Math.min(cnt1(cpy), cnt2(cpy)));
			}
		}

		writer.write(Integer.toString(answer));
	}

	int cnt1(int[][] arr) {
		int cnt = 0;

		for (int i = 0; i < arr.length; ++i) {
			cnt += diff(arr[i], i % 2 == 0 ? pattern1 : pattern2);
		}

		return cnt;
	}

	int cnt2(int[][] arr) {
		int cnt = 0;

		for (int i = 0; i < arr.length; ++i) {
			cnt += diff(arr[i], i % 2 == 1 ? pattern1 : pattern2);
		}

		return cnt;
	}

	int diff(int[] a, int b[]) {
		int cnt = 0;

		for (int i = 0; i < a.length; ++i) {
			if (a[i] != b[i]) {
				cnt++;
			}
		}

		return cnt;
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

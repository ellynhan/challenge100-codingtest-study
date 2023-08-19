import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	StringTokenizer tokenizer;

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

		// 산술평균
		int sum = 0;
		for (int n : arr) {
			sum += n;
		}
		writer.write(Integer.toString((int)Math.round((double)sum/N)));
		writer.newLine();

		// 중앙값
		writer.write(Integer.toString(arr[N/2]));
		writer.newLine();

		// 최빈값
		Map<Integer, Integer> map = new LinkedHashMap<>();
		for (int n : arr) {
			map.put(n, map.getOrDefault(n, 0)+1);
		}

		int maxValue = Integer.MIN_VALUE;

		for (int n : map.values()) {
			maxValue = Math.max(maxValue, n);
		}

		int finalMaxValue = maxValue;
		int[] i = map.entrySet().stream()
			.filter(entry -> entry.getValue() == finalMaxValue)
			.sorted(Comparator.comparingInt(Map.Entry::getKey))
			.mapToInt(Map.Entry::getKey)
			.toArray();

		writer.write(Integer.toString(i.length >= 2 ? i[1] : i[0]));
		writer.newLine();

		// 범위
		writer.write(Integer.toString(arr[arr.length-1]-arr[0]));
	}

	public static void main(String[] args) throws IOException {
		Main main = new Main();

		main.input();
		main.solve();

		main.reader.close();
		main.writer.close();
	}
}

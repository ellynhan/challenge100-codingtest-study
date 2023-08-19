import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	static StringTokenizer tokenizer;

	static int N;
	static Info[] infos;

	public static void main(String[] args) throws IOException {
		input();
		solve();

		writer.close();
		reader.close();
	}

	static void input() throws IOException {
		N = Integer.parseInt(reader.readLine());

		infos = new Info[N];

		for (int i = 0; i < N; ++i) {
			tokenizer = new StringTokenizer(reader.readLine());

			infos[i] = new Info();
			infos[i].idx = i+1;
			infos[i].x = Integer.parseInt(tokenizer.nextToken());
			infos[i].y = Integer.parseInt(tokenizer.nextToken());
			infos[i].t = Integer.parseInt(tokenizer.nextToken());
		}
	}

	static void solve() throws IOException {
		Arrays.sort(infos, Comparator.comparingDouble(Info::getTime));

		for (Info info : infos) {
			writer.write(Integer.toString(info.idx));
			writer.newLine();
		}
	}

	static class Info {
		public int idx;
		public int x;
		public int y;
		public int t;

		public double getTime() {
			return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) / t;
		}
	}
}

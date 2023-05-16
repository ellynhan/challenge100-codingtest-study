package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution_1477_휴게소 {
	static class Info implements Comparable<Info> {
		int len, cnt; // 사이 구간의 길이, 사이의 휴게소 개수

		public Info(int len, int cnt) {
			super();
			this.len = len;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Info o) {
			int oV = o.len / o.cnt;
			if (o.len % o.cnt != 0)
				oV += 1;
			int thisV = this.len / this.cnt;
			if (this.len % this.cnt != 0)
				thisV += 1;

			return oV - thisV;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());

		PriorityQueue<Info> pq = new PriorityQueue<>();

		int[] rest = new int[N + 2];
		rest[0] = 0;
		rest[N + 1] = L;

		if (N > 0) {
			st = new StringTokenizer(br.readLine());
		}
		for (int i = 0; i < N; i++) {
			rest[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(rest);
		for (int i = 1; i <= N + 1; i++) {
			pq.offer(new Info(rest[i] - rest[i - 1], 1));
		}

		for (int i = 0; i < M; i++) {
			Info currMax = pq.poll();
			pq.offer(new Info(currMax.len, currMax.cnt + 1));
		}

		Info max = pq.peek();
		int answer = max.len % (max.cnt) == 0 ? max.len / (max.cnt) : max.len / (max.cnt) + 1;
		System.out.println(answer);
	}
}
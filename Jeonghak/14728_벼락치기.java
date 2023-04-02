package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_14728 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken());

		int[][] D = new int[N + 1][T + 1];
		int[] time = new int[N + 1];
		int[] point = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			time[i] = Integer.parseInt(st.nextToken());
			point[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= T; j++) {
				if (j < time[i]) {
					D[i][j] = D[i - 1][j];
				} else {
					D[i][j] = Math.max(D[i - 1][j - time[i]] + point[i], D[i - 1][j]);
				}
			}
		}

		System.out.println(D[N][T]);
	}
}
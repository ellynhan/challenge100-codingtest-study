package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_2636_치즈 {
	static int[] dr = { 0, 0, 1, -1 };
	static int[] dc = { 1, -1, 0, 0 };
	static int[] memo;
	static int answer;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] map = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		memo = new int[101];
		while (!findSurface(map).isEmpty()) {
			answer++;
		}

		System.out.println(answer);
		System.out.println(memo[answer - 1]);

	}

	static Queue<int[]> findSurface(int[][] map) {
		Queue<int[]> queue = new ArrayDeque<>();
		Queue<int[]> surface = new ArrayDeque<>();
		queue.offer(new int[] { 0, 0 });
		boolean[][] visit = new boolean[map.length][map[0].length];
		visit[0][0] = true;

		while (!queue.isEmpty()) {
			int[] curr = queue.poll();
			for (int i = 0; i < 4; i++) {
				int nr = curr[0] + dr[i];
				int nc = curr[1] + dc[i];

				if (nr < 0 || nc < 0 || nr >= map.length || nc >= map[0].length || visit[nr][nc])
					continue;

				visit[nr][nc] = true;

				if (map[nr][nc] == 1) {
					surface.offer(new int[] { nr, nc });
					map[nr][nc] = 0;
					memo[answer]++;
				} else
					queue.offer(new int[] { nr, nc });
			}
		}

		return surface;
	}
}
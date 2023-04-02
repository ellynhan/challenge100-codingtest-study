package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/*
반례 : 이전에 먼저 방문했더라도 말 움직임의 순서에 따라 도착여부가 달라질 수 있다.
1
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 0
*/
public class Solution_1600_말이되고픈원숭이 {
	static int K, W, H, answer = -1;
	static int[][] board;
	static int[] dy = { 0, 0, 1, -1 };
	static int[] dx = { 1, -1, 0, 0 };
	static int[] horsey = { 2, 2, 1, 1, -2, -2, -1, -1 };
	static int[] horsex = { 1, -1, -2, 2, 1, -1, 2, -2 };

	static class Info {
		int y, x, k, t;

		public Info(int y, int x, int k, int t) {
			super();
			this.y = y;
			this.x = x;
			this.k = k;
			this.t = t;
		}

	}

	public static void main(String[] args) throws Exception {
		Input();
		move();
		System.out.println(answer);
	}

	static void move() {
		Queue<Info> queue = new ArrayDeque<>();
		boolean[][][] visit = new boolean[H][W][K + 1];
		queue.add(new Info(0, 0, 0, 0));
		visit[0][0][0] = true;

		while (!queue.isEmpty()) {
			Info curr = queue.poll();
			if (curr.y == H - 1 && curr.x == W - 1) {
				answer = curr.t;
				break;
			}

			if (curr.k < K) {
				for (int i = 0; i < 8; i++) {
					int ny = curr.y + horsey[i];
					int nx = curr.x + horsex[i];
					if (ny < 0 || nx < 0 || ny >= H || nx >= W || visit[ny][nx][curr.k + 1] || board[ny][nx] == 1)
						continue;
					visit[ny][nx][curr.k + 1] = true;
					queue.offer(new Info(ny, nx, curr.k + 1, curr.t + 1));
				}
			}

			for (int i = 0; i < 4; i++) {
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W || visit[ny][nx][curr.k] || board[ny][nx] == 1)
					continue;
				visit[ny][nx][curr.k] = true;
				queue.offer(new Info(ny, nx, curr.k, curr.t + 1));
			}
		}
	}

	static void Input() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		board = new int[H][W];
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
}

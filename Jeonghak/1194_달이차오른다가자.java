package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution1194_달이차오른다가자 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		char[][] maze = new char[N][M];
		int[] start = new int[3];

		for (int i = 0; i < N; i++) {
			maze[i] = br.readLine().toCharArray();
			for (int j = 0; j < M; j++) {
				if (maze[i][j] == '0')
					start = new int[] { i, j, 0, 0 };
			}
		}

		System.out.println(BFS(N, M, maze, start));
	}

	private static int BFS(int N, int M, char[][] maze, int[] start) {
		int minDistance = -1;
		int[] dx = { 0, 0, 1, -1 };
		int[] dy = { 1, -1, 0, 0 };

		Queue<int[]> queue = new ArrayDeque<>();
		boolean[][][] visit = new boolean[64][N][M]; // bit masking 한 값을 visit의 index로 사용

		queue.offer(start);

		while (!queue.isEmpty()) {
			int[] curr = queue.poll();

			if (maze[curr[0]][curr[1]] == '1') {
				minDistance = curr[2];
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = curr[0] + dy[i];
				int nx = curr[1] + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || maze[ny][nx] == '#' || visit[curr[3]][ny][nx])
					continue;

				int check = curr[3];

				if (maze[ny][nx] >= 'A' && maze[ny][nx] <= 'F') {
					if ((check & (1 << (maze[ny][nx] - 'A'))) == 0)
						continue;
				}

				if (maze[ny][nx] >= 'a' && maze[ny][nx] <= 'f') {
					check = getCheck(curr[3], maze[ny][nx]);
				}

				visit[check][ny][nx] = true;
				queue.offer(new int[] { ny, nx, curr[2] + 1, check });
			}

		}

		return minDistance;
	}

	private static int getCheck(int check, char key) {
		int n = key - 'a';
		check = check | (1 << n);
		return check;
	}
}

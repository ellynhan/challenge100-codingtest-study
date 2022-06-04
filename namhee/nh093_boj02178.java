// boj2178 미로 탐색 (21:48 ~ 22:08)
import java.util.Scanner;

public class nh093_boj02178 {
	
	static int N, M;
	static int[][] arr;	// 1 : 이동 가능, 0 : 이동 불가
	static int[][] dist;
	
	// 상 하 좌 우
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { -1, 1, 0, 0 };
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			String line = sc.next();
			for (int j = 0; j < M; j++) {
				arr[i][j] = line.charAt(j) - '0';
			}
		}
		
		dist = new int[N][M];
		bfs();
		
		System.out.println(dist[N - 1][M - 1]);
	}

	private static void bfs() {
		int[] queueX = new int[N * M];
		int frontX = -1, rearX = -1;
		int[] queueY = new int[N * M];
		int frontY = -1, rearY = -1;

		queueX[++rearX] = 0;
		queueY[++rearY] = 0;
		dist[0][0] = 1; // visited 겸 최소 이동 칸 수(거리) 체크

		while (frontX != rearX) {
			int x = queueX[++frontX];
			int y = queueY[++frontY];
			
			int newX, newY;
			for (int i = 0; i < 4; i++) {
				newX = x + dx[i];
				newY = y + dy[i];

				if (isWall(newX, newY)) continue;
				
				if (arr[newY][newX] == 1 && dist[newY][newX] == 0) {
					queueX[++rearX] = newX;
					queueY[++rearY] = newY;
					dist[newY][newX] = dist[y][x] + 1;
					
					if (newY == N -1 && newX == M - 1) return;
				}
			}
		}
	}

	private static boolean isWall(int x, int y) {
		return y < 0 || y >= N || x < 0 || x >= M;
	}
}

// (1, 1) 에서 출발하여 (N, M)(맨 오른쪽 맨 아래)의 위치로 이동할 때 지나야 하는 최소의 칸 수 구하기
// (1, 1)에서 bfs 탐색을 시작해 (N, M)을 지날 때 return
// 이동할 때는 인접한 칸으로 이동 (인접 = 상하좌우)

// Q. (N, M)은 무조건 이동 가능한 위치로 나오는 건가요? => YES

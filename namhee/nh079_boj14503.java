// boj14503 로봇청소기 (20:30~21:20)
import java.util.Scanner;

public class nh079_boj14503 {
	
	static int[][] map; // 0 : 빈 칸, 1 : 벽이자 이미 청소한 곳.
	// 첫, 마지막 행과 열은 벽이기에 우리가 따로 isWall을 만들 필요가 없다.
	static int N, M;
	static int r, c, d;
	
	// 북 : 0, 동 : 1, 남 : 2, 서 : 3 이라고 하네^^
	// 0 -> 3 -> 2 -> 1 -> 0이군요 .... (북 -> 서 -> 남 -> 동 -> 북) 하 ㅠ
	// d - i를 해서, -1되면 +4 해줘야 하는 그런 순서네요
	static int[] dr = { -1, 0, 1, 0 };
	static int[] dc = { 0, 1, 0, -1 };
	static int Answer;
	
	public static void main(String[] args) {
		
		// 1. 데이터 입력
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		d = sc.nextInt();
		
		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		
		// 2. 청소 시작~
		clean();
		
		System.out.println(Answer);
	}

	private static void clean() {
		Answer = 0;
		
		while (true) {
			// 1. 현재 위치를 청소 - 후진했던 그 장소를 이미 청소했을 수도 있음.
			if (map[r][c] == 0) {
				map[r][c] = 2; // 1을 2로 바꿔보자.
				Answer++;
			}
			
			// 2. 다음 청소할 곳을 탐색한다.
			int newR, newC, newD;
			boolean found = false;
			for (int i = 1; i <= 4; i++) { // 현재 방향을 기준으로 왼쪽부터. 현재 방향부터 아님.
				// 탐색 방향 설정
				newD = d - i;
				if (newD < 0) {
					newD += 4;
				}
				newR = r + dr[newD];
				newC = c + dc[newD];
				
				// a. 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한칸 전진, 없다면 다음 방향 탐색
				if (map[newR][newC] == 0) {
					d = newD;	r = newR;	c = newC;
					found = true;
					break;
				}
			}
			
			if (!found) { // 후진하거나, 그만(return)하거나.
				// "바라보는 방향을 유지 한 채로" 후진.
				r = r + dr[(d + 2) % 4];
				c = c + dc[(d + 2) % 4];
				
				// 후진했는데 벽이면 return
				if (map[r][c] == 1) {
					return;
				}
			}
		}	
	}
}

// 청소하는 영역의 개수 구하기
// 아하 나의 로직의 문제점을 알아냈음.
// 벽과 청소한 공간은 다름. 벽은 절대 이동하지 못하는 장소지만, 청소한 공간은 이동은 가능함. 단지 카운트가 안 될 뿐이지.

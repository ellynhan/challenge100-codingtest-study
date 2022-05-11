// boj21608 상어 초등학교 (20:48 ~ 21:48, 1시간)
import java.util.Scanner;

public class nh089_boj21608 {
	
	static int N;
	static int[][] classroom; // N x N (한 변 크기) = 학생의 수
	// 학생 정보, 0번 인덱스의 학생부터 차례대로 자리를 정해보자.
	static int[][] student;
	// 상, 하, 좌, 우
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };
	
	static int[] seatRow;
	static int[] seatCol;
		
	public static void main(String[] args) {
		
		// 1. 데이터 입력 받기
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		classroom = new int[N][N];
		student = new int[N * N][5];
		for (int i = 0; i < N * N; i++) {
			for (int j = 0; j <= 4; j++) {
				student[i][j] = sc.nextInt();
			}
		}
		
		// 2. 자리 배치하기
		seatRow = new int[N * N];
		seatCol = new int[N * N];
		setClassroom();
		
		// 3. 만족도 구하기
		int Answer = 0;
		int newR, newC, count;
		for (int i = 0; i < N * N ; i++) {
			count = 0;
			for (int j = 0; j < 4; j++) {
				newR = seatRow[i] + dr[j];
				newC = seatCol[i] + dc[j];
				
				if (!isWall(newR, newC)) {
					for (int k = 1; k <= 4; k++) {
						if (classroom[newR][newC] == student[i][k]) {
							count++;
							break;
						}
					}
				}
			}
			Answer += (int) Math.pow(10, count - 1);
		}
		
		System.out.println(Answer);
	}

	private static void setClassroom() {
		
		// i번째 학생을 자리 배치하는 과정. (N*N번 반복.)
		for (int idx = 0; idx < N * N; idx++) {
			// 조건1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
			// 1. 비어 있는 칸을 조사한 정보를 check1에 저장하고, max, maxCount 정보를 조사합니다.
			int check1[][] = new int[N][N];
			int max1 = -1; int maxCount1 = 0;
			int maxRow1 = 0; int maxCol1 = 0;

			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (classroom[r][c] == 0) {
						int newR, newC;
						for (int i = 0; i < 4; i++) {
							newR = r + dr[i];
							newC = c + dc[i];
							if (!isWall(newR, newC)) {
								for (int j = 1; j <= 4; j++) {
									if (classroom[newR][newC] == student[idx][j]) {
										check1[r][c]++;
										break;
									}
								}
							}
						}
						
						if (check1[r][c] > max1) {
							max1 = check1[r][c];
							maxCount1 = 1;
							maxRow1 = r;
							maxCol1 = c;
						}
						else if (check1[r][c] == max1){
							maxCount1++;
						}
					}
				}
			}
			
			// max가 하나라면, 자리 배치 끝
			if (maxCount1 == 1) {
				classroom[maxRow1][maxCol1] = student[idx][0];
				seatRow[idx] = maxRow1;
				seatCol[idx] = maxCol1;
				continue;
			}
			
			// 위의 max1값과 일치하는 칸만 조사한다는 사실을 잊지 말자.
			// 조건2. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
			int check2[][] = new int[N][N];
			int max2 = -1; int maxCount2 = 0;
			int maxRow2 = 0; int maxCol2 = 0;

			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					
					if (classroom[r][c] == 0 && check1[r][c] == max1) {
						int newR, newC;
						for (int i = 0; i < 4; i++) 
						{
							newR = r + dr[i];
							newC = c + dc[i];
							if (!isWall(newR, newC) && classroom[newR][newC] == 0) {
								check2[r][c]++;
							}
						}
						
						if (check2[r][c] > max2) {
							max2 = check2[r][c];
							maxCount2 = 1;
							maxRow2 = r;
							maxCol2 = c;
						}
						else if (check2[r][c] == max2){
							maxCount2++;
						}
					}
				}
			}
			
			// 조건3. max가 하나거나 아니라면 행 번호가 가장 작고, 열 번호가 가장 작은 걸로 자리 배치 끝
			classroom[maxRow2][maxCol2] = student[idx][0];
			seatRow[idx] = maxRow2;
			seatCol[idx] = maxCol2;
		}		
	}

	private static boolean isWall(int r, int c) {
		return r < 0 || r >= N || c < 0 || c >= N;
	}
}

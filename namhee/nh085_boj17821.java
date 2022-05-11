// boj17821 야구 (1시간 40분)
import java.util.Scanner;

public class nh085_boj17821 {

	static int N; // 이닝 정보
	static int[][] result; // 각 선수가 각 이닝에서 얻는 결과
	static int[] player = new int[10]; // 선수 순서
	static boolean[] checked = new boolean[10]; // 순열 중복 체크
	
	static boolean[] atBat = new boolean[4];
	static int Answer; // 답을 저장하는 변수
	
	public static void main(String[] args) {
		
		// 데이터 입력
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		result = new int[10][N];
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= 9; j++) {
				result[j][i] = sc.nextInt();
			}
		}

		// 선수 타순 정하기 & 최고 득점 구하기
		player[4] = 1;
		checked[1] = true;
		perm(1);
		
		System.out.println(Answer);
	}

	private static void perm(int n) { 
		if (n == 10) {
			getScore();
			return;
		}
		
		for (int i = 2; i <= 9; i++) {
			if (checked[i]) continue;

			checked[i] = true;
			player[n] = i;
			if (n == 3) {
				perm(n + 2);
			}
			else {
				perm(n + 1);
			}
			checked[i] = false;
		}
	}

	private static void getScore() {
		// 선공
		for (int i = 1; i < 4; i++) {
			atBat[i] = false;
		}
		
		int inning = 0, out = 0;
		int order = 1;
		int score = 0;
		while (inning < N) {
			out = 0;
			while (out < 3) {
				if (result[player[order]][inning] == 0) {
					out++;
				}
				else if (result[player[order]][inning] == 1) {
					if (atBat[3] == true) {
						atBat[3] = false;
						score++;
					}
					for (int i = 2; i >= 1; i--) {
						if (atBat[i] == true) {
							atBat[i] = false;
							atBat[i + 1] = true; 
						}
					}
					atBat[1] = true;
				}
				else if (result[player[order]][inning] == 2) {
					for (int i = 2; i < 4; i++) {
						if (atBat[i] == true) {
							atBat[i] = false;
							score++;
						}
					}
					if (atBat[1] == true) {
						atBat[1] = false;
						atBat[3] = true;
					}
					atBat[2] = true;
				}
				else if (result[player[order]][inning] == 3) {
					for (int i = 1; i < 4; i++) {
						if (atBat[i] == true) {
							atBat[i] = false;
							score++;
						}
					}
					atBat[3] = true;
				}
				else if (result[player[order]][inning] == 4) {
					for (int i = 1; i < 4; i++) {
						if (atBat[i] == true) {
							atBat[i] = false;
							score++;
						}
					}
					score++;
				}
				order++;
				if (order == 10) {
					order = 1;
				}
			}

			for (int i = 1; i < 4; i++) {
				atBat[i] = false;
			}

			inning++;
		}
		Answer = score > Answer ? score : Answer;
	}
}

// 답이 안 나왔던 이유...
// 선후공으로 나누는 것도 생각해야 하는 줄 알았는데 아니었다.
// ((그럼 대체 왜 공격 수비 정보를 준 겁니까....))
// ( -> 니가 예제 출력에서 눈치챘어야 했음.)

// 9명으로 이우어진 두 팀.
// 공격과 수비를 번갈아 하는 게임.
// 하나의 이닝 : 공격과 수비 x N
// 한 이닝 : 3아웃 발생 시, 이닝 종료. 공수 교체.

// 경기 시작 전, 타순 결정. (중간에 못 바꿈.)
// 9번 타자가 공을 쳤는데 아웃 X 1번 타자가 다시 타석으로.
// 타순은 다음 이닝에도 이어진다.

// 공격 : 타자가 공을 침. -> 1루 -> 2루 -> 3루 -> 홈 = 1점
// => 안타, 2루타, 3루타, 홈런, 아웃

// 타순을 정하려고 한다.
// 1번 선수를 4번 타자로 미리 결정했고,
// 다른 선수의 타순을 모두 결정해야 한다.

// 각 이닝에서 어떤 결과를 얻는지 미리 알고 있을 때,
// 가장 많은 득점을 하는 타순을 찾고, "그 때의 득점을 구해보자."

// 8명 배치 순열 8! = 720 x 56 = 40,320

// N : 이닝 수 (<= 50)
// 각 줄 : 각 선수 9명이 이닝에서 얻는 결과 (각 이닝에 0 기록하는 타자가 적어도 한 명 존재)
// 	1: 안타 / 2: 2루타 / 3: 3루타 / 4: 홈런 / 0: 아웃

// 8! x 50 = 2 x 10^6 가지

// 이닝 정보 50가지를 다 따져야 하는 걸까 아니면,
// 공수 순서도 따져서 25가지를 따져봐야 하는 걸까? -> 이게 맞는 것 같지?
// 그럼 득점을 구할 때 공수 순서를 따져서 최댓값을 구해야 겠다.
// -> 아, 안 따지는 구나...??

// for문 10회를 깊 8만큼 하면... 시간 초과되겠는데...?
// 이 순열을 어떻게 줄이지?

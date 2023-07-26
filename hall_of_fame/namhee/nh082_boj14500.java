// boj14500 테트로미노 (21:18 ~ 22:10)


import java.util.Scanner;

public class nh082_boj14500 {
	
	static int N, M;
	static int[][] num;
	static int Answer;
	
	public static void main(String[] args) {
		
		// INPUT DATA
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		num = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				num[i][j] = sc.nextInt();
			}
		}
		
		// MAX 탐색 시작
		getMaxBySquare(); 	// ㅁ, 1가지
		getMaxByBar(); 		// ㅡ, 2가지
		getMaxByT();		// ㅗ, 4가지
		getMaxBySZ();		// Z / S, 4가지
		getMaxByL();		// L, 8가지
		
		System.out.println(Answer);
		
	}

	private static void getMaxByL() {
		int max = 0, tmp = 0;

		// |
		// |
		// ㅡ ㅡ
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i + 2][j];
				tmp += num[i + 2][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;		

		//   |
		//   |
		// ㅡ ㅡ
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j + 1];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j];
				tmp += num[i + 2][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		// ㅡ ㅡ 
		// | 
		// |
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i + 1][j];
				tmp += num[i + 2][j];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		// ㅡ ㅡ 
		//   | 
		//   |
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		// | 
		// ㅡ ㅡ ㅡ
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 1][j + 2];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		//     | 
		// ㅡ ㅡ ㅡ
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j + 2];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 1][j + 2];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		// ㅡ ㅡ ㅡ
		//     | 
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i][j + 2];
				tmp += num[i + 1][j + 2];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

		// ㅡ ㅡ ㅡ
		// | 
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i][j + 2];
				tmp += num[i + 1][j];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;

	}

	private static void getMaxBySZ() {
		int max = 0, tmp = 0;

		// Z
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 1][j + 2];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("Z에서 제일 큰 값 : %d%n", max);
		
		// S
		max = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j + 1];
				tmp += num[i][j + 2];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("S에서 제일 큰 값 : %d%n", max);
		
		// |
		// | |
		//   |
		max = 0;
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("에서 제일 큰 값 : %d%n", max);
		
		//   |
		// | |
		// |
		max = 0;
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j + 1];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("N에서 제일 큰 값 : %d%n", max);

	}

	private static void getMaxByT() {
		int max = 0, tmp = 0;

		// ㅗ
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j + 1];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 1][j + 2];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("ㅗ에서 제일 큰 값 : %d%n", max);
		
		// ㅓ
		max = 0;
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j + 1];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("ㅓ에서 제일 큰 값 : %d%n", max);

		// ㅜ
		max = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 2; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i][j + 2];
				tmp += num[i + 1][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("ㅜ에서 제일 큰 값 : %d%n", max);

		// ㅏ
		max = 0;
		for (int i = 0; i < N - 2; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i + 1][j + 1];
				tmp += num[i + 2][j];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		//System.out.printf("ㅏ에서 제일 큰 값 : %d%n", max);
	}

	private static void getMaxByBar() {
		int max = 0, tmp = 0;

		// 가로 모양
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= M - 4; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i][j + 1];
				tmp += num[i][j + 2];
				tmp += num[i][j + 3];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		// System.out.printf("가로 Bar에서 제일 큰 값 : %d%n", max);
		
		// 세로 모양
		max = 0;
		for (int i = 0; i <= N - 4; i++) {
			for (int j = 0; j < M; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i + 2][j];
				tmp += num[i + 3][j];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		// System.out.printf("세로 Bar에서 제일 큰 값 : %d%n", max);
	}

	private static void getMaxBySquare() {
		int max = 0, tmp = 0;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				tmp = 0;
				
				tmp += num[i][j];
				tmp += num[i + 1][j];
				tmp += num[i][j + 1];
				tmp += num[i + 1][j + 1];

				max = tmp > max ? tmp : max;
			}
		}
		Answer = max > Answer ? max : Answer;
		// System.out.printf("Square에서 제일 큰 값 : %d", max);
	}
}

// 폴리오미노 : 정사각형을 여러 개 이어 붙인 도형
// 1. 정사각형은 서로 겹치면 안 된다. = 독립적인 칸을 유지한다. = 배열 일부 모양이다.
// 2. 도형은 모두 연결되어 있어야 한다. = 같은 폴리오미노는 상하좌우 스타일로 맞닿아 있다.
// 3. 정사각형의 변끼리 연결되어 있어야 한다 = 상하좌우
// (정작 해보니까 이 성질을 이요해서 뭔갈 할 수는 없었어)

// 테트로미노 = 정사각형 4개를 이어 붙인 폴리오미노 종류는 5가지

// NxM인 종이 위에 테트로미노 "하나"를 놓으려고 한다.
// 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
// "회전" "대칭" 가능 -> 미친

// 정사각형 - 회전 대칭해도 1가지
// 작대기 - 2가지 - ㅣ
// L자 - 8가지
// ㄹ자? 얘는 4가지
// ㅗ자 - 4가지
// 총 19가지의 테트로미노를...

// 최대 500x500 = 25 * 10^4 * 4 = 10^6번 (1가지 테트로미노 탐색)
// 약 20가지 * 10^6 = 2*10^7번 탐색인듯

// (입력으로 주어지는 수는 1,000을 넘지 않으니 절대 합이 int 범위를 넘길리 없다.)
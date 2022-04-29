// nh091_boj24954 물약 구매 (19:15 ~ 20:05)
import java.util.Scanner;

public class nh091_boj24954 {
	
	static int N;
	static int[] c;	// price
	static int[] p; // 각 i번째의 할인 정보 개수
	static int[][] a; // i번째의 할인 물약 번호 리스트 (i행의 p열 만큼의 정보를 사용하면 됨) 
	static int[][] d; // i번째의 할인 물약 번호의 할인 가격 리스트

	static boolean[] visited;
	static int[] order;
	
	static int Answer = 10001;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		// 1. 데이터 입력 받기
		N = sc.nextInt();
		c = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			c[i] = sc.nextInt();
		}
		
		p = new int[N + 1];
		a = new int[N + 1][N];
		d = new int[N + 1][N];
		for (int i = 1; i <= N; i++) {
			p[i] = sc.nextInt();
			for (int j = 0; j < p[i]; j++) {
				a[i][j] = sc.nextInt();
				d[i][j] = sc.nextInt();
			}
		}
		
		// 2. 순열
		visited = new boolean[N + 1];
		order = new int[N + 1];
		perm(0);
		
		System.out.println(Answer);
	}

	private static void perm(int depth) {
		// 순열 구하면 Answer 구하기
		if (depth == N) {
			// 할인 정보 적용 전 정보를 임시 변수에 저장.
			int[] tmpC = new int[N + 1];
			for (int i = 1; i <= N; i++) {
				tmpC[i] = c[i];
			}

			int sum = 0;
			int idx;
			for (int i = 0; i < N; i++) {
				// 순열 i번째 인덱스의 물약 구매
				idx = order[i];
				sum += tmpC[idx];

				// 구매 후, 할인 정보 적용시키기
				for (int j = 0; j < p[idx]; j++) {
					if (tmpC[a[idx][j]] - d[idx][j] < 1) {
						tmpC[a[idx][j]] = 1;
					}
					else {
						tmpC[a[idx][j]] -= d[idx][j];						
					}					
				}
			}
			
			Answer = sum < Answer ? sum : Answer;
			
			return;
		}
		
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				order[depth] = i;
				perm(depth + 1);				
				visited[i] = false;
			}
		}
	}
}

//입력
// N 		물약의 종류
// c_i		각 물약의 가격
// N개의 라인 	물약의 할인 정보
// p_i (a_j, d_j)	-> 물약 번호 a, 할인되는 가격 d -> i번째를 사면 p_i종류의 다른 물약의 가격이 내려감
	// .....뭔소리야?

// 입력 예
// 4	물약 4종류
// 10 15 20 25	각 물약의 가격
// 2	1번째 물의 할인 정보 개수
// 3 10	3번째가 10개 할인
// 2 20	2번째가 20개 할인
// 0	2번째 물의 할인 정보 개수
// 1	3번째 물의 할인 정보 개수
// 4 10 4번째 물의 할인 정보 개수 


// N종류의 물약을 모두 구매하려고 한다.
// 물약은 1번부터 N번까지 번호가 매겨져 있다.
// i번째 물약의 가격은 동전 c_i개
// i번째 물약을 구매하면 p_i종류의 다른 물약의 가격이 내려간다. & 할인은 중첩된다.
// 단! 동전 개수는 1개가 최솟값입니다!
	// -> 어쩐지 순서가 중요할 것 같은 문제다. (오, 문제에서 힌트로 찝어주기까지 하네) => 순열!!
	// 오 심지어 N은 최댓값이 10입니다!^^ (10! = 3,628,800 홀뤼 걍 순열로 풀자~!~!)

// Q. 물약을 가장 싸게 샀을 때 그 비용을 알려주자.


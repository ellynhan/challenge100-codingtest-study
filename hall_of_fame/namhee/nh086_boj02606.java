// boj2606 바이러스 (19:55 ~ 20:40)
import java.util.Scanner;

public class nh086_boj02606 {

	static int N, M; // 컴퓨터 수, 연결선 수
	static boolean[][] edge; // 연결 정보 (undirected)
	static int Answer;
	
	public static void main(String[] args) {
		
		// 데이터 입력 받기
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		edge = new boolean[N + 1][N + 1];
		
		M = sc.nextInt();
		int v1, v2;
		for (int i = 0; i < M; i++) {
			v1 = sc.nextInt();
			v2 = sc.nextInt();
			
			edge[v1][v2] = true;
			edge[v2][v1] = true;
		}
		
		// 1번 컴퓨터가 감염되었을 때, 
		// 웜 바이러스에 걸리게 되는 컴퓨터 개수 구하기
		// bfs(1);
		dfs(1);
		
		System.out.println(Answer);
		// 주의할 점은 1번 컴퓨터를 통해 바이러스에 걸리게 되는 컴퓨터 수를 구하는 것이기 때문에
		// 1번 컴퓨터는 개수에서 제외해야 한다.
		
		sc.close();
	}

	private static void bfs(int start) {
		// 0. 초기화
		int[] queue = new int[N];
		int front = -1, rear = -1;
		boolean[] visited = new boolean[N + 1]; // 범위를 N으로 지정하는 바람에 indexOutOfBound 발생
		
		// 1. start 지점 값 설정
		queue[++rear] = start;
		visited[start] = true;
		
		// 2. BFS 탐색
		int v;
		while (front != rear) {
			v = queue[++front]; // 탐색할 vertex pop
			
			for (int i = 1; i <= N; i++) {
				if (edge[v][i] && !visited[i]) {
					queue[++rear] = i;
					visited[i] = true;
					Answer++;
				}
			}
		}
	}
	
	private static void dfs(int start) {
		// 0. 초기화
		int[] stack = new int[M];
		// stack 크기를 N으로 잡으면 에러가 난다.
		// dfs는 stack은 pop할 때 visited를 체크하기 때문에 
		// 최대 edge 개수만큼 쌓일 수 있다!
		int top = -1;
		boolean[] visited = new boolean[N + 1];
		
		// 1. start 지점 값 설정
		stack[++top] = start;
		
		// 2. DFS 탐색 시작
		int v;
		Answer = -1; // 1번 컴퓨터를 고려하지 않기 위해서
		while (top > -1) {
			v = stack[top--];
			if (!visited[v]) { // 또한 visited를 체크해야 중복으로 체크하지 않는다! 주의하자!
				visited[v] = true;
				Answer++;
				
				for (int i = 1; i <= N; i++) {
					if (edge[v][i] && !visited[i]) {
						stack[++top] = i;
					}
				}				
			}
		}
	}
}

// 웜 바이러스에 걸린 컴퓨터와 
// 같은 네트워크에 연결되어 있는 컴퓨터들은
// 전파되어 같은 바이러스에 걸리게 된다.

// Q. 컴퓨터 수와 서로 연결되어 있는 정보가 주어질 때, 
//	"1번 컴퓨터를 통해" 원 바이러스에 걸리게 되는 컴퓨터의 수를 구하자.

// 컴퓨터의 수 N은 100개 이하. 1번 ~ N번 -> 연결 정보를 배열로 만들어도 나쁘지 않다.
// 연결되어 있는 컴퓨터 쌍의 수 M이 주어진다. -> 몇 개의 입력을 받느냐에 대한 정보이다.
// 연결 되어 있는 컴퓨터의 번호 쌍 M개의 줄
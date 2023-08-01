// BOJ 1260 : DFS와 BFS (12:55 ~ 01:15)
// DFS, BFS 구현 복습용으로 푸는 문제
import java.util.Scanner;

public class nh087_boj01260 {

	static int N, M, V;
	static boolean[][] edge;
	static int[] stack;
	static int[] queue;
	static boolean[] visited;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		
		edge = new boolean[N + 1][N + 1];
		int v1, v2;
		for (int i = 0; i < M; i++) {
			v1 = sc.nextInt();
			v2 = sc.nextInt();
			edge[v1][v2] = true;
			edge[v2][v1] = true;
		}
		
		dfs(V);
		System.out.println();
		bfs(V);
	}
		
	private static void bfs(int start) {
		// 0. 초기화
		queue = new int[N];
		int front = -1, rear = -1;
		visited = new boolean[N + 1];
		
		// 1. 시작 지점 체크
		queue[++rear] = start;
		visited[start] = true;
		System.out.print(start + " ");
		
		// 2. 탐색 시작
		int v;
		while (front != rear) {
			v = queue[++front];
			
			for (int w = 1; w <= N; w++) {
				if (edge[v][w] && !visited[w]) {
					queue[++rear] = w;
					visited[w] = true;
					System.out.print(w + " ");
				}
			}
		}
	}

	private static void dfs(int start) {
		// 0. 초기화
		stack = new int[M];
		int top = -1;
		visited = new boolean[N + 1]; 
		
		// 1. 시작 지점 체크
		stack[++top] = start;
		
		// 2. 탐색 시작
		int v;
		while (top > -1) {
			v = stack[top--];
			
			if (!visited[v]) {
				visited[v] = true;
				System.out.print(v + " ");
				
				// 후입선출 구조임을 고려하면 가장 큰 것부터 집어넣어야 작은 번호부터 탐색 가능하다.
				for (int w = N; w >= 1; w--) {
					if (edge[v][w] && !visited[w]) {
						stack[++top] = w;
					}
				}
			}
		}
	}
}

// 정점의 개수가 1 <= N <= 1000
// 간선의 개수가 1 <= M <= 10000 이므로
// 인접 행렬은 정점 개수가 좀 많지만 메모리 제한을 초과하진 않는다. 
// 		다만, 행렬이 10^6인 거에 비해 간선은 10^4개인 걸 생각하면 비효율적이다.
// 하지만 정점 번호가 작은 것부터 방문해야 하기 때문에 정렬하는 수고는 덜 수 있다.

// 인접리스트로 할 경우 우선순위 큐와 같은 자료구조를 사용하거나, 정렬 하는 것을 고려해야 한다.

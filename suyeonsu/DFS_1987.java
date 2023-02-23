import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int R, C;
	static char[][] board;
	static boolean[] visited = new boolean[26];
	static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	static int answer = Integer.MIN_VALUE;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		board = new char[R][C];
		for(int i=0; i<R; i++) {
			board[i] = br.readLine().toCharArray();
		}
		visited[board[0][0]-'A'] = true;
		dfs(0, 0, 1);
		System.out.println(answer);
	}

	private static void dfs(int x, int y, int cnt) {
		int flag = 0;
		for(int i=0; i<4; i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if(0 <= nx && nx < R && 0 <= ny && ny < C) {
				int ch = board[nx][ny]-'A';
				if(!visited[ch]) {
					flag = 1;
					visited[ch] = true;
					dfs(nx, ny, cnt+1);
					visited[ch] = false;
				}
			}
		}
		if(flag == 0) answer = Math.max(answer, cnt);
	}
}

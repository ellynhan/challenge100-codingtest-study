import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int R, C;
	static char[][] board;
	static int[] dr = {-1, 0, 1};
	static int answer;
	static int flag;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		board = new char[R][C];
		for(int i=0; i<R; i++) {
			board[i] = br.readLine().toCharArray();
		}
		
		for(int r=0; r<R; r++) {
			board[r][0] = '-';
			flag = 0;
			setPipe(r, 0);
		}
		System.out.println(answer);
	}

	private static void setPipe(int r, int c) {
		if(c == C-1) {
			flag = 1;
			answer++;
			return;
		}
		for(int d=0; d<3; d++) {
			int nr = r+dr[d], nc = c+1;
			if(flag == 0 && 0 <= nr && nr < R && board[nr][nc] == '.' ) {
				board[nr][nc] = '-';
				setPipe(nr, nc);
			}
		}
	}

}

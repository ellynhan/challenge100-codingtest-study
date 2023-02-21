import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int[] col;	// i: 행, col[i]: 열
	static int N;
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		col = new int[N];
		nQueen(0);
		System.out.println(answer);
	}

	private static void nQueen(int row) {
		if(row == N) {
			answer++;
			return;
		}
		for(int c=0; c<N; c++) {
			col[row] = c;
			if(promising(row)) { // row 행이 유망하다면
				nQueen(row+1);
			}
		}
	}
	
	private static boolean promising(int row) {
		for(int r=0; r<row; r++) {
			if(col[r] == col[row] ||
					Math.abs(col[r]-col[row]) == Math.abs(r-row)) return false;
		}
		return true;
	}

}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M, K;
	static int[][] A, a;
	static int[][] list;
	static List<int[]> Case;
	static int[] sel;
	static boolean[] isSelected;
	static int r, c, s;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		A = new int[N][M];
		a = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				a[i][j] = A[i][j];
			}
		}
		
		list = new int[K][3];
		for(int i=0; i<K; i++) {
			st = new StringTokenizer(br.readLine());
			list[i] = new int[] {Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())};
		}

		Case = new ArrayList<>();
		sel = new int[K];
		isSelected = new boolean[K];
		permutations(0);
		
		int answer = Integer.MAX_VALUE;
		for(int[] order : Case) {
			
			for(int i=0; i<N; i++) {
				A[i] = Arrays.copyOf(a[i], M);
			}
			
			for(int idx : order) {
				rotate(list[idx][0], list[idx][1], list[idx][2]);
			}
			
			int minSum = Integer.MAX_VALUE;
			for(int i=0; i<N; i++) {
				int sum = 0;
				for(int j=0; j<M; j++) {
					sum += A[i][j];
				}
				minSum = Math.min(minSum, sum);
			}
			answer = Math.min(answer, minSum);
		}
		System.out.println(answer);
	}

	private static void permutations(int cnt) {
		if(cnt == K) {
			Case.add(Arrays.copyOf(sel, K));
			return;
		}
		for(int i=0; i<K; i++) {
			if(!isSelected[i]) {
				sel[cnt] = i;
				isSelected[i] = true;
				permutations(cnt+1);
				isSelected[i] = false;
			}
		}
	}

	private static void rotate(int r, int c, int s) {
		List<int[]> idx;
		int x, y;
		for(int k=s; k>0; k--) {
			idx = new ArrayList<>();
			x = r-k;
			y = c-k;
			// +y
			while(y <= c+k) {
				idx.add(new int[] {x, y++});
			}
			// +x
			y = c+k;
			x = r-k+1;
			while(x <= r+k) {
				idx.add(new int[] {x++, y});
			}
			// -y
			y = c+k-1;
			x = r+k;
			while(y >= c-k) {
				idx.add(new int[] {x, y--});
			}
			// -x
			y = c-k;
			x = r+k-1;
			while(x > r-k) {
				idx.add(new int[] {x--, y});
			}
			
			int tmp = A[idx.get(idx.size()-1)[0]][idx.get(idx.size()-1)[1]];
			for(int i=idx.size()-1; i>0; i--) {
				int[] to = idx.get(i);
				int[] from = idx.get(i-1);
				A[to[0]][to[1]] = A[from[0]][from[1]];
			}
			A[idx.get(0)[0]][idx.get(0)[1]] = tmp;
		}
	}

}

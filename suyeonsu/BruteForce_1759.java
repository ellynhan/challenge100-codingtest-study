import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int L, C;
	static String[] letter, sel;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		letter = new String[C];
		letter = br.readLine().split(" ");
		sel = new String[L];
		
		Arrays.sort(letter);
		combinations(0, 0);
	}

	private static void combinations(int cnt, int idx) {
		if(cnt == L) {
			int a = 0, b = 0;
			for(int i=0; i<L; i++) {
				if(sel[i].equals("a") || sel[i].equals("e") || sel[i].equals("i") || sel[i].equals("o") || sel[i].equals("u")) a++;
				else b++;
			}
			if(a >= 1 && b >= 2) {
				for(int i=0; i<L; i++) {
					System.out.print(sel[i]);
				}
				System.out.println();
			}
			return;
		}
		for(int i=idx; i<C; i++) {
			sel[cnt] = letter[i];
			combinations(cnt+1, i+1);
		}
	}

}

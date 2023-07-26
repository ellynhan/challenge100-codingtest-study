// boj10250 ACM Hotel (23:32 ~ 23:40)
import java.util.Scanner;

public class nh083_boj10250 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		int H, W, N, x, y;
		for (int tc = 0; tc < T; tc++) {
			H = sc.nextInt();
			W = sc.nextInt();
			N = sc.nextInt();
			
			y = ((N - 1) % H) + 1;
			x = ((N - 1) / H) + 1;
			
			if (x < 10) {
				System.out.printf("%d0%d%n", y, x);
			}
			else {
				System.out.printf("%d%d%n", y, x);
			}
		}
	}
}

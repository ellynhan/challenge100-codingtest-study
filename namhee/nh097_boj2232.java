import java.util.Scanner;

public class nh097_boj2232 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int result = 0;
		for(int i = 1; i < N; i++) {
			int M = i;
			int sum = M;
			while (M > 0) {
				sum += M % 10;
				M = M / 10;
			}
			
			if (sum == N) {
				result = i;
				break;
			}
		}
		
		System.out.println(result);
	}
}

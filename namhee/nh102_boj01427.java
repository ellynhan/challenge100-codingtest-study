import java.util.Arrays;
import java.util.Scanner;

public class nh102_boj01427 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String inp = sc.next();
		char[] charArr = inp.toCharArray();
		Arrays.sort(charArr);
		String res = String.valueOf(charArr);
		
		for (int i = res.length() - 1; i >= 0; i--) {
			System.out.print(res.charAt(i));
		}
	}
}

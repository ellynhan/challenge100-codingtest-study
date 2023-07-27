import java.util.Scanner;

public class nh084_boj01259 {

	static String str;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		while (true) {
			str = Integer.toString(sc.nextInt());
			if (str.equals("0"))
				break;
			
			check();
		}
	}

	private static void check() {
		int len = str.length();
		for (int i = 0; i < len / 2; i++) {
			if (str.charAt(i) != str.charAt(len - 1 - i)) {
				System.out.println("no");
				return;
			}
		}
		System.out.println("yes");
	}
}

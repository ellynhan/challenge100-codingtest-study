import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 0;
		for (int i = 0; i < 5; i++) {
			int inp = sc.nextInt();
			num += Math.pow(inp, 2);
		}
		
		System.out.println(num%10);
	}
}

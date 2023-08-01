import java.util.Scanner;

public class nh096_boj1101 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String line;
		int count = 0;
		for (int i = 0; i < 8; i++) {
			line = sc.nextLine();
			for (int j = 0; j < 8; j++) {
				if ((i % 2 == 0 && j % 2 == 0) ||
						(i % 2 == 1 && j % 2 == 1)) {
					if (line.charAt(j) == 'F') {
						count++;
					}
				}
			}
		}
		
		System.out.println(count);
	}
}

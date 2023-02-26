import java.util.Scanner;

public class Main {

	static StringBuilder answer = new StringBuilder();
	static char[][] board;
	
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 int n = sc.nextInt();
		 board = new char[n][n];
		 for(int i=0; i<n; i++) {
			 board[i] = sc.next().toCharArray();
		 }
		 zip(0, 0, n);
		 System.out.println(answer);
	}

	private static void zip(int x, int y, int size) {
		int tot = 0;
		for(int i=x; i<x+size; i++) {
			for(int j=y; j<y+size; j++) {
				tot += board[i][j] - 48;
			}
		} 
		if(tot == size*size) answer.append('1');
		else if(tot == 0) answer.append('0');
		else {
			answer.append('(');
			zip(x, y, size/2);
			zip(x, y+size/2, size/2);
			zip(x+size/2, y, size/2);
			zip(x+size/2, y+size/2, size/2);
			answer.append(')');
		}
	}

}

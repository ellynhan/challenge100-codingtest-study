import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// String input = br.readLine();
		// System.out.println("Hello Goorm! Your input is " +input);
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		int sum = 0;
		int min = 0;
		
		for(int i = N; i>=M; i--){
			for(int j=1; j*j<=N; j++){
				if(i == j*j){
					min = i;
					sum += i;
				}
			}
		}
		System.out.println(min + " "+sum);
	}
}

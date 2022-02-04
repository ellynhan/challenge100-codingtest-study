import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// String input = br.readLine();
		// System.out.println("Hello Goorm! Your input is " + input);
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		double s = (a+b+c) / 2.0;
		double res = Math.sqrt(s * ((s-a)*(s-b)*(s-c)));
		
		System.out.println(String.format("%.2f", res));
		
		//하하,, 헤론의 공식은
		// s = a+b+c/2, 삼각형의넓이 = sqrt(s*(s-a)*(s-b)*(s-c))
		//인것이다.....
	}
}

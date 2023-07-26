// boj2908 상수 (10min)
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class nh099_boj02908 {
	public static void main(String[] args) throws IOException {
		// 1. INPUT DATA (A & B - 3 digits int, A != B)
		// 각 A와 B에는 0이 없다고 한다.

		// 1-A. Scanner input (메모리 17.5MB, 시간 204ms)
//		Scanner sc = new Scanner(System.in);
//		int A = sc.nextInt();
//		int B = sc.nextInt();
		
		// 1-B. BufferedReader input (메모리 14MB, 시간 120ms)
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		// 2. GET REVERSE NUM
		int rvsA = 0;
		int rvsB = 0;
		for (int i = 0; i < 3; i++) {
			rvsA *= 10;
			rvsB *= 10;
			
			rvsA += A % 10;	
			rvsB += B % 10;
			
			A /= 10;
			B /= 10;
		}
		// rvsA = (A % 10 * 100) + (A % 100 - A % 10) + (A / 100);
		// rvsB = (B % 10 * 100) + (B % 100 - B % 10) + (B / 100);
		// 자릿수가 3으로 고정되어 있으니 위와 같이 나타내는 게 더 나았을 수도?
		// 역시 큰 속도 차이는 없더라.
		
		// 3. COMPARE & OUTPUT
		//System.out.print(rvsA > rvsB ? rvsA : rvsB);
		System.out.print(Math.max(rvsA, rvsB));
		// 이 둘의 큰 속도 차이는 없더라.
	}
}

// (digit 10^0 -> 10^1 -> 10^2를 차례대로 비교하자.)
// -> 어짜피 출력을 뒤집힌 숫자로 해야 하니 뒤집는 작업부터 해주자.

// String 내장 함수 쓰면 코드가 훨씬 간결해지겠지만,
// String을 쓰는 거니까 메모리랑 시간 면에서는 불리할 것 같음. 확인해보자.
// String 출력하지 말란 얘기는 없는데 일단..
// java는 문자열 뒤집는 게 python처럼 간단하지 않군
// reverse를 생각해봤는데 오히려 java에선 비효율적인 것 같아.

// boj02258 A + B - 2
// Scanner 대신 BufferedReader 쓰는 연습 겸 하루 한 문제는 풀고 싶어서 풀어본 문제
// Scanner 썼을 때 : Memory 17.728MB, 시간 204ms
// BufferedReader 썼을 때 : Memory 14.172MB 시간 124ms
// 간단한 A + B 출력에도 꽤 많은 차이가 난다! (테스트 케이스 몇 갠지 모르는 게 좀 아쉽다...)
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class nh077_boj02558 {
	
	public static void main(String[] args) throws IOException { // br 쓸 때는 IOException을 추가해야 함.
		
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//int A = sc.nextInt();
		//int B = sc.nextInt();
		int A = Integer.parseInt(br.readLine());
		int B = Integer.parseInt(br.readLine());
		
		System.out.println(A + B);
	}
}

// Java로 알고리즘 공부한지 이제 2달 되어 가는데 아직 익숙하지 않고 모르는 게 많다...,,,
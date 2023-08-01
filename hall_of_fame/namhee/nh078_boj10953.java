// boj10953 A+B - 6 (22:30~22:50)
// 콤마(,) 구분은 최근 문제 트렌드와는 거리가 멀다고 하지만 
// 자바 입출력에서 어찌 구분할 줄 모르기 때문에 해보면 좋을 것 같았다.

// split 또는 StringTokenizer를 사용하면 구분해서 입력받을 수 있다.
// 둘의 시간 차이는 거의 없다.

// 입력의 복잡도 차이는 Scanner vs. BufferedReader에 영향을 많이 받는다.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class nh078_boj10953 {
	
	public static void main(String[] args) throws IOException {
		
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {

			int sum = 0;
			
			/* 1. Scanner & split 쓰기 (시간 : 224ms / 메모리 : 17816KB)
			String[] str = sc.next().split(",");
			int A = Integer.parseInt(str[0]);
			int B = Integer.parseInt(str[1]);
			sum = A + B;
			*/
			
			/* 2. Scanner & StringTokenizer 쓰기 (시간 : 220ms / 메모리 : 17772KB)
			String str = sc.next();
			StringTokenizer st = new StringTokenizer(str, ",");

			while(st.hasMoreTokens()) {
				sum += Integer.parseInt(st.nextToken());
			}
			*/
			
			/* 3. BuffedReader & split 사용 (시간 : 136ms / 메모리 : 14208KB)
			String[] str = br.readLine().split(",");
			int A = Integer.parseInt(str[0]);
			int B = Integer.parseInt(str[1]);
			sum = A + B;
			*/
			
			// 4. BuffedReader & StringTokenizer (시간 : 136ms / 메모리 : 14136KB)
			StringTokenizer st = new StringTokenizer(br.readLine(), ",");
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			sum = A + B;
						
			System.out.println(sum);
		}
	}
}

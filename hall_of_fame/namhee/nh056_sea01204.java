// 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기 
import java.util.Scanner;

class nh056_sea01204 { // SEA에서는 반드시 class명을 Solution으로 제출해야 합니다!!
	public static void main(String[] args) {		
	
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{		
			/////////////////////////////////////////////////////////////////////////////////////////////
            // 최빈수를 출력하는 프로그램을 작성
			final int studentNum = 1000;
            
            // 1. 데이터 입력 받기
            int score = 0;
            int no = sc.nextInt(); // 현재 테스트케이스 번호
            int[] scoreNum = new int[101];
            for (int i = 0; i < studentNum; i++) {
                score = sc.nextInt();
               	scoreNum[score]++;
            }
            
            // 2. 최빈값 찾기
            int maxIndex = 0;
            int maxNum = 0;
            for (int i = 100; i >= 0; i--) {
                if (maxNum < scoreNum[i]) {
                    maxNum = scoreNum[i];
                    maxIndex = i;
                }
            }
            
			// 3. 결과(최빈값) 출력
            System.out.println("#" + no + ' ' + maxIndex);
			/////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
}

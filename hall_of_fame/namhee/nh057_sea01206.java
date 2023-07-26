// 1206. [S/W 문제해결 기본] 1일차 - View
import java.util.Scanner;

class nh057_sea01206 { // SEA에서는 반드시 class명을 Solution으로 제출해야 합니다!!

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		int[] building = new int[1000];
        for(int test_case = 1; test_case <= 10; test_case++)
        {
         
            /////////////////////////////////////////////////////////////////////////////////////////////
            // 1. 데이터 입력
            int width = sc.nextInt();
            for (int i = 0; i < width; i++) {
                building[i] = sc.nextInt();
            }
             
            // 2. 조망권 확보 세대 수 구하기
            int view = 0;
            for (int i = 2; i < width-2; i++) {
                int maxFloor = 0;
                for (int j = i - 2; j <= i + 2; j++) {
                    if (i != j && maxFloor < building[j]) {
                        maxFloor = building[j];
                    }
                }
                 
                int viewNum = building[i] - maxFloor;
                if (viewNum >= 1) {
                    view += viewNum;                    
                }
            }
             
            System.out.printf("#%d %d%n", test_case, view);
            /////////////////////////////////////////////////////////////////////////////////////////////
 
        }
	}
}
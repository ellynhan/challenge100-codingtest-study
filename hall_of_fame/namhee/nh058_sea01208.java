// 1208. [S/W 문제해결 기본] 1일차 - Flatten
import java.util.Scanner;

public class nh058_sea01208 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
        for(int test_case = 1; test_case <= 10; test_case++)
        {
         
            /////////////////////////////////////////////////////////////////////////////////////////////
            // 1. 데이터 입력
            int N = sc.nextInt();
            int[] box = new int[100];
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            int maxIndex = -1;
            int minIndex = -1;
            for (int i = 0; i < 100; i++) {
                box[i] = sc.nextInt();
                if (max < box[i]) {
                    max = box[i];
                    maxIndex = i;
                }
                if (min > box[i]) {
                    min = box[i];
                    minIndex = i;
                }
            }
             
            int diff = max-min; // diff값이 1이하면 dump할 필요 없음.
            // 2. N만큼 Dump!
            while ((N--)!=0 && diff > 1) {
                // 2-1. 평탄화
                box[maxIndex]--;
                box[minIndex]++;
                // 2-2. 다시 max, min 탐색 -> 중복이라 손을 좀 봐야 할 듯
                max = Integer.MIN_VALUE;
                min = Integer.MAX_VALUE;
                for (int i = 0; i < 100; i++) {
                    if (max < box[i]) {
                        max = box[i];
                        maxIndex = i;
                    }
                    if (min > box[i]) {
                        min = box[i];
                        minIndex = i;
                    } 
                }
                diff = max-min;
            }
             
            // 3. 최고점, 최저점 차 출력
            System.out.printf("#%d %d%n", test_case, diff);
            /////////////////////////////////////////////////////////////////////////////////////////////
 
        }
    }
}
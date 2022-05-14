import java.util.Scanner;

public class nh092_boj02292 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int sum = 0;
		int dist = 1;
		while (true) {
			if ((N - 1) <= 6 * sum) break;

			sum += dist;
			dist++;
		}
		
		System.out.println(dist);
	}
}

// 1 (+0)
// 2 ~ 7 (+6) layer2 6*1
// 8 ~ 19 (+12) layer3 6*2
// 20 ~ 37 (+18) layer4 6*3

// 0 (<= 6*0)
// 1 ~ 6 (<= 6*1)
// 7 ~ 18 (<= 6*(1+2))
// 19 ~ 36 (<= 6*(1+2+3))
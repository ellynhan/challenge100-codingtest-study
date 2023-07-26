// boj1946 신입 사원 (16:30 ~ 17:00)
package com.algo.week04;

import java.util.Scanner;

public class BOJ1946 {
		
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] secondScore;
		for (int test_case = 0; test_case < T; test_case++) {
			
			int N = sc.nextInt();
			secondScore = new int[N + 1];
			for (int i = 0; i < N; i++) {
				int firstScore = sc.nextInt();
				secondScore[firstScore] = sc.nextInt();
			}

			// 위와 같이 입력을 받으면 sort 과정이 필요 없어진다!
			// sort 과정을 없앴더니 시간 초과가 나지 않았다.
			
			int num = 1;
			int tmpScore = secondScore[1];
			for (int i = 2; i <= N; i++) {
				if (tmpScore > secondScore[i]) {
					num++;
					tmpScore = secondScore[i];
				}
			}
			
			System.out.println(num);
		}
		
	}
}

package com.algo.practice.boj;

import java.util.Scanner;

public class nh066_boj01244 {
	
	static int[] light = new int[101];
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);		
		int N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			light[i] = sc.nextInt();
		}
		
		int studentNum = sc.nextInt();
		for (int i = 0; i < studentNum; i++) {
			int isMale = sc.nextInt();
			int swNum = sc.nextInt();
			if (isMale == 1)
				turnLight1(swNum, N);
			else if (isMale == 2)
				turnLight2(swNum, N);
		}
		
		// 주의 : 한줄에 20개 출력
		for (int i = 1; i <= N; i++) {
			if (i != 1 && i%20 == 1)
				System.out.println();
			System.out.printf("%d ", light[i]);
		}
	}

	private static void turnLight1(int swNum, int N) {
		for (int i = swNum; i <= N; i += swNum) {			
			light[i] = light[i] == 0 ? 1 : 0;
		}
		
	}

	private static void turnLight2(int swNum, int N) {
		light[swNum] = light[swNum] == 0 ? 1 : 0;
		
		int left = swNum - 1;
		int right = swNum + 1;
		while (true) {
			if (left < 1 || right > N) break;
			if (light[left] != light[right]) break;
			
			light[left] = light[left] == 0 ? 1 : 0;
			light[right] = light[right] == 0 ? 1 : 0;

			left--;	right++;
		}
		
	}
}

// 개인적으로 보니까 이거는 잘 읽고 이해해서
// 순서대로 차근차근 코딩하면 되는 문제인 것 같다.

// 프로그램 읽을 때 좋게 변수 이름을 명확하게 적자.
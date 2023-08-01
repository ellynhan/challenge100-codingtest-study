package com.algo.week04;

import java.util.Scanner;

public class BOJ2579 {
		
	static int N;
	static int[] score;
	static int[] dp;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		score = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			score[i] = sc.nextInt();
		}
		
		getMaxScore();
		
		System.out.println(dp[N]);
	}

	private static void getMaxScore() {
		dp = new int[N + 1];
		dp[0] = 0;
		
		if (N >= 1)
			dp[1] = score[1];
		if (N >= 2)
			dp[2] = score[1] + score[2];
		
		for (int i = 3; i <= N; i++) {
			dp[i] = Math.max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
		}		
	}
}

// 규칙
// 1. 한 번 - 한 계단 or 두 계단
// 2. "연속된 세 개의 계단을 모두 밟아서는 안된다."
// 3. "마지막 도착 계단은 반드시 밟아야 한다."

// ...? 연속된 세 개의 계단을 밟지 않아야 하고, 마지막 도착 계단은 밟아야 하면 이걸 어케 앎?
// 계단 개수 300개, 계단에 쓰여 있는 점수는 10,000 이하의 자연수
// 거꾸로 가도 규칙은 똑같이 적용된단 말이지....
// 그럼 base 조건 초기화를 20으로 한 뒤에
// 두 칸 앞에 있는 게 더 크면 뛰고, 그거 아니면 가까이에 있는 걸로 가고
// 2번 왔으면 자연스럽게 두 칸 점프하고.
// 이렇게 해볼까?
// boj2559 수열 (21:50~22:05, 15분)
package com.algo.practice.boj;

import java.util.Scanner;

public class BOJ2559 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] temp = new int[N];
		for (int i = 0; i < N; i++)
			temp[i] = sc.nextInt();
		
		int max = Integer.MIN_VALUE;
		for (int i = 0; i <= N-K; i++) {
			int sum = 0;
			for (int j = i; j < i+K; j++) {
				sum += temp[j];
			}
			max = max > sum ? max : sum;
		}
		
		System.out.println(max);
	}
}

/* 문제 이해
 * 연속 며칠 동안의 온도의 합이 가장 큰 값을 알아보자.
 * 입력 : 온도 측정 날짜 수 = 수열의 크기(N), 합을 구할 연속적인 날짜의 수(K), 온도값(temp)
 * 2 <= N <= 100,000,  1 <= K <= N, -100 <= temp <= 100
 
 * 문제 설계
 * 이 문제는 N-K+1만큼 브루트포스로 온도의 합을 조사하고 최댓값을 구하는 문제 
 * for in K로 합을 구한다.
 * 주의 : 합계를 구하는 for문을 시작 위치를 i부터 해줘야 한다!
 */

// 문제에서 나올 수 있는 최솟값을 당연히 -101이라 생각했다가 생각해보니 최솟값은 -100*100,000 = -10^7이다

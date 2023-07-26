// boj 14225 부분수열의 합 (25분 소요)
package com.algo.week02;

import java.util.Scanner;

public class nh071_boj14225 {
	
	static int[] S = new int[20];
	static boolean[] isPossibleSum;
	
	public static void main(String[] args) {
		
		// INPUT DATA
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++)
			S[i] = sc.nextInt();
		
		// SEARCH DATA - use bit op
		isPossibleSum = new boolean[N*100000 + 1]; // 모든 숫자의 합을 최대 크기로 하는 게 좋을듯
		for (int i = 1; i < 1 << N; i++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				if ((1 & i >> k) == 0) continue;
				sum += S[k];
			}
			isPossibleSum[sum] = true;
		}
		
		// OUTPUT DATA
		int answer = 0;
		for (int i = 1; i <= N*100000; i++) {
			if (!isPossibleSum[i]) {
				answer = i;
				break;
			}
		}
		System.out.println(answer);
	}
}

/* 문제 이해
 * 수열 S가 주어졌을 때, 수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 프로그램
 * 입력 N (수열 원소의 개수) / 수열 S (원소들은 100,000보다 작거나 같음) -> int 배열[2000
 
 * 수열 원소 20개의 진부분집합의 개수 : 2^20 - 1 = 1,048,575 (나쁘지 않은 개수)
 */

/* 문제 설계
 * 1. N 입력받기 (탐색 범위를 정하는 데에 사용될 예정)
 * 2, 수열 S 입력받기 (전역변수에 저장) (for 0 ~ N)
 * 3. 비트연산으로 선택된 수열들의 합을 sum 배열 나온 거라면 1 대입 isPossibleSum
 * 4. for (isPossibleSum 1 <= N*100,000)
 	0인 값 탐색하기
 	
 	(Worst 탐색 횟수 : 1,048,575 + 2,000,000 ㄱㅊㄱㅊ)
 */
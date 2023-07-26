// [Silver5] BOJ 7568 덩치 : 키와 몸무게로 등수 매기기
// 자신보다 더 큰 사람의 수+1가 덩치 등수
// 더 크다 : 키와 몸무게가 모두 나보다 많다
package com.algo100.week02;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ7568 {
	public static void main(String[] args) {
		
		// 1. INPUT DATA
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		int[] w = new int[num];
		int[] h = new int[num];
		for (int i = 0; i < num; i++) {
			w[i] = sc.nextInt();
			h[i] = sc.nextInt();
		}
		sc.close();
		
		// 2. GET RANK
		int[] rank = new int[num];
		Arrays.fill(rank, 1);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (i != j) {
					if (w[i] < w[j] && h[i] < h[j]) {
						rank[i]++;
					}
				}
			}
		}
		
		// 3. OUTPUT DATA
		for (int i = 0; i < num; i++) {
			System.out.printf("%d ", rank[i]);			
		}
	}
}

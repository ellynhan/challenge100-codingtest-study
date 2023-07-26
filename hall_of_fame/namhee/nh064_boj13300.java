// boj 13300 πÊπË¡§ (22:56~23:05)
package com.algo.practice;

import java.util.Scanner;

public class nh064_boj13300 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		int[] girl = new int[7];
		int[] boy = new int[7];
		
		int S, Y;
		int result = 0;
		for (int i = 0; i < N; i++) {
			S = sc.nextInt();
			Y = sc.nextInt();
			
			if (S == 0) {
				girl[Y]++;
				if (girl[Y] == K) {
					result++;
					girl[Y] = 0;
				}
			}
			else if (S == 1) {
				boy[Y]++;
				if (boy[Y] == K) {
					result++;
					boy[Y] = 0;
				}
			}
		}
		
		for (int i = 1; i <= 6; i++) {
			if (boy[i] != 0) result++;
			if (girl[i] != 0) result++;
		}
		
		System.out.println(result);
	}
}

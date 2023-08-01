package com.algo.practice;

import java.util.Scanner;

public class nh065_boj14696 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		for (int test_case = 0; test_case < N; test_case++) {
			int A[] = new int[5];
			int numA = sc.nextInt();
			for (int i = 0; i < numA; i++) {
				A[sc.nextInt()]++;
			}

			int B[] = new int[5];
			int numB = sc.nextInt();
			for (int i = 0; i < numB; i++) {
				B[sc.nextInt()]++;
			}			
			
			char winner = 'D';
			for (int i = 4; i >= 1; i--) {
				if (A[i] > B[i]) {
					winner = 'A';
					break;
				}
				else if (B[i] > A[i]) {
					winner = 'B';
					break;					
				}
			}
			System.out.println(winner);
		}
	}
}


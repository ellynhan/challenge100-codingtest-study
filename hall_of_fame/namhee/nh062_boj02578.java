// boj2578 : 빙고 (22:15~22:45, 30분)
package com.algo.practice.boj;

import java.util.Scanner;

public class BOJ2578 {
	public static void main(String[] args) {
		
		final int SIZE = 5;
		
		Scanner sc = new Scanner(System.in);
		int[][] table = new int[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				table[i][j] = sc.nextInt();
		
		int[][] num = new int[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				num[i][j] = sc.nextInt();
		
		int[][] bingo = new int[SIZE][SIZE];
		int result = 0;
		for (int N = 0; N < SIZE*SIZE; N++) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					if (table[i][j] == num[N/5][N%5])
						bingo[i][j] = 1;
				}
			}
			
			if (N >= 10) {
				int check = 0;
				int line = 0;
				
				for (int i = 0; i < SIZE; i++) {
					check = 0;
					for (int j = 0; j < SIZE; j++) {
						if (bingo[i][j] == 1)
							check++;
					}
					if (check == 5) {
						line++;
					}
				}
				
				for (int j = 0; j < SIZE; j++) {
					check = 0;
					for (int i = 0; i < SIZE; i++) {
						if (bingo[i][j] == 1)
							check++;
					}
					if (check == 5) {
						line++;
					}
				}					

				check = 0;
				for (int i = 0; i < SIZE; i++) {
					if (bingo[i][i] == 1)
						check++;
				}
				if (check == 5) {
					line++;
				}
				
				check = 0;
				for (int i = 0; i < SIZE; i++) {
					if (bingo[SIZE-i-1][i] == 1)
						check++;
				}
				if (check == 5) {
					line++;
				}
				
				if (line >= 3) {
					result = N+1;
					break;
				}
			}
		}
		
		System.out.println(result);
	}
}

/* 문제 설계
 * 변수 : table[5][5]
 * 입력 : table값 -> 지울 숫자 
 
 * 실행 횟수
 * 지울 때 : 순회 한번(25) * 25 = 625
 * 값을 찾을 때 : 숫자를 부르는 횟수(25)*순회해서 확인하는 횟수(25+25+2) = 1300
 * 약 2500이라고 봐도...
 */
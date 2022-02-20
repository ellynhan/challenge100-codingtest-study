// boj 10157 자리배정 (22:00~23:24, 84분)
package com.algo.practice;

import java.util.Scanner;

public class nh063_boj10157 {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int C = sc.nextInt();
		int R = sc.nextInt();
		int[][] seat = new int[R][C];
		int K = sc.nextInt();
		
		int i = 0, j = 0;
		int newI = R-1, newJ = 0;
		
		if (C*R >= K) {
			int di[] = {-1, 0, 1, 0};
			int dj[] = {0, 1, 0, -1};
			int dir = 0;
			for (int N = 1; N <= C*R; N++) {					
				i = newI;
				j = newJ;
				seat[i][j] = N; 
				
				if (N == K) break;
							
				newI = i + di[dir];
				newJ = j + dj[dir];
				
				if (isWall(newI, newJ, R, C) || seat[newI][newJ] != 0) {
					dir = (dir + 1) % 4;
					newI = i + di[dir];
					newJ = j + dj[dir];
				}
			}
			System.out.printf("%d %d%n", j+1, R-i);
		}
		else {
			System.out.println(0);
		}

//		for (int r = 0; r < R; r++) {
//			for (int c = 0; c < C; c++) {
//				System.out.print(seat[r][c] + "\t");
//			}
//			System.out.println();
//		}
	}

	private static boolean isWall(int i, int j, int R, int C) {
		return (i < 0 || i >= R || j < 0 || j >= C);
	}
}

/* 문제 풀이
   1. 주어진 배열 채워 나가기
    배열의 크기 : 1000x1000(10^3 * 10^3) = 10^6
    (거기에 대기번호가 K인데 K가 배열 넓이보다 크다면 탐색하지 말고 0 출력)
 	방향을 바꾸는 조건 : 이미 값이 있음(좌석값이 0이 아님) / 배열 범위를 벗어남
 	방향을 바꾸는 방법 : 상(0)->우(1)->하(2)->좌(3)->상(0)->... 
   
 */
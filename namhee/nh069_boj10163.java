package com.algo.practice.boj;

import java.util.Scanner;

public class nh069_boj10163 {

	static int[][] paperInfo = new int[1001][1001];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int paperIdx = 1; paperIdx <= N; paperIdx++) {
			int startX = sc.nextInt();
			int startY = 1001 - sc.nextInt() - 1;
			int width = sc.nextInt();
			int height = sc.nextInt();
			
			for (int x = startX; x < startX + width; x++) {
				for (int y = startY; y > startY - height; y--) {
					paperInfo[x][y] = paperIdx;
				}
			}			
		}
		
		int[] paperAreaNum = new int[N + 1];
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				if (paperInfo[i][j] != 0)
					paperAreaNum[paperInfo[i][j]]++;
			}
		}
		
		for (int i = 1; i <= N; i++)
			System.out.println(paperAreaNum[i]);
	}
}

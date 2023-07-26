// 2117. [모의 SW 역량테스트] 홈 방범 서비스 (1시간)
package com.algo.day20.swea;

import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA2117 {

	static int N, M;
	static int[][] map;
	static int[][] distance;
	static int[] di = { 0, 0, 1, -1 };
	static int[] dj = { 1, -1, 0, 0 };
	static int Answer;
	
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/swea2117_input.txt"));

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			M = sc.nextInt();
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			Answer = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					bfs(i, j);
				}
			}
			
			System.out.println("#" + test_case + " " + Answer);
		}
	}

	private static void bfs(int startI, int startJ) {
		distance = new int[N][N];
		int[] queue = new int[N * N * 2];
		int front = -1, rear = -1;
		
		queue[++rear] = startI;
		queue[++rear] = startJ;
		distance[startI][startJ] = 1;
		
		int count = 0;
		if (map[startI][startJ] == 1) {
			count++;
			Answer = count > Answer ? count : Answer;
		}
		
		int i, j;
		while (front != rear) {
			i = queue[++front];
			j = queue[++front];
			
			int newI, newJ;
			for (int dir = 0; dir < 4; dir++) {
				newI = i + di[dir];
				newJ = j + dj[dir];
				if (isWall(newI, newJ) || distance[newI][newJ] > 0)	continue;
				
				queue[++rear] = newI;
				queue[++rear] = newJ;
				distance[newI][newJ] = distance[i][j] + 1;
				
				if (map[newI][newJ] == 1) {
					count = count + 1;
					getMaxHomeNum(count, newI, newJ);				
				}
			}
		}
	}

	private static void getMaxHomeNum(int count, int i, int j) {
		int K = distance[i][j];
		int cost = K * K + (K - 1) * (K - 1);
		
		if (cost <= count * M) {
			Answer = count > Answer ? count : Answer;
		}
	}

	private static boolean isWall(int i, int j) {
		return i < 0 || i >= N || j < 0 || j >= N;
	}
}

// 가구 수를 미리 세어서 CUT하는 코드를 추가할 수도 있겠다. 일단 지금은 다 탐색하는 걸로.
// 그리고 전체 가구 수 * M해서 K 운영 비용이 그 이상을 넘어가면 아예 탐색하지 않을수도 있겠지.

// <문제 풀이 시간>
// 교수님 왈, 일단 완전 검색을 한 다음에 최적화를 하는 게 맞다
// homeXY를 미리 구해놓고 거리가 K보다 작은지 탐색하는 방법도 있을 수 있겠다.
// 교수님의 logic은 K가 가장 클 때 구한 값이 0보다 크면 return
// 왜냐하면, K일 때 구한 답이 K의 범위를 줄이면서 구한 답보다 크거나 같기 때문이다.

// (나도 최적화가 아니라 최대 개수를 구하라는 것에서
//  좀 더 쉽고 다른 간단한 로직을 짤 수 있을 거라고 감이 오긴 했는데 실제로 적용한 겉 없네)

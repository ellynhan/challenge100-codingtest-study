package com.algo.week02;

import java.util.Scanner;

public class nh070_boj01012 {
	
	static boolean[][] nonVisited = new boolean[50][50];
	static int N, M, K;
	
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test_case = 0; test_case < T; test_case++) {

			// INPUT DATA
			M = sc.nextInt();
			N = sc.nextInt();
			K = sc.nextInt();
			for (int i = 0; i < K; i++) {
				int X = sc.nextInt();
				int Y = sc.nextInt();
				nonVisited[Y][X] = true;
			}
			
			// 완전 탐색, dfs로 배추 집합 개수 구하기
			int setNum = getSetNum();
			
			System.out.println(setNum);	
		}
	}

	private static int getSetNum() {
		
		int num = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (nonVisited[y][x]) {
					dfs(x, y);
					num++;
				}
			}
		}
		return num;
	}

	private static void dfs(int x, int y) {
		nonVisited[y][x] = false;
		
		for (int i = 0; i < 4; i++) { // 연결된 정점 탐색
			if (!isWall(x + dx[i], y + dy[i]) && nonVisited[y + dy[i]][x + dx[i]]) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}

	private static boolean isWall(int x, int y) {
		return x < 0 || x >= M || y < 0 || y >= N;
	}
}

/* 문제 이해
 * 배추근처(4방(상하좌우))에 서식해 해충을 잡아 먹음으로써 배추를 보호.
 * 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 "이 지렁이는 인접한 다른 배추로 이동할 있다."(역시 보호받음)
 * 
 * 몇 마리의 지렁이가 필요한지 알아보아라.
 */

/* 문제 설계
	1. 일단 데이터를 모두 입력받아라.
	2. 완전 탐색, dfs로 배추 집합 개수 구하기
	 - 완전 탐색 : 다 visited 했나
	 - dfs : 배추 집합이 어떻게 이어지는지 파악 (dfs 시작 1번 = 집합 1개)
	3. dfs 시작 횟수 = 배추 집합 개수 출력하기 
 */
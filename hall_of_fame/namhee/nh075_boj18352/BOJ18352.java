// boj18532. 특정 거리의 도시 찾기 (20:40 ~ 21:20)
// 나중에 다익스트라로도 풀어봐야 겠다...,,,
package com.algo.week05;

import java.util.ArrayList;
import java.util.Scanner;

// sol1. BFS로 접근
public class BOJ18352 {

	static int N, M, K, X;
	static ArrayList<ArrayList<Integer>> graph;
	static int[] queue;
	static int[] distance;
	static boolean isExist;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		X = sc.nextInt();
		
		// 1. 인접리스트를 이용한 그래프 초기화
		graph = new ArrayList<ArrayList<Integer>>();
		// 1-1. 노드 개수만큼 생성
		for (int i = 0; i < N + 1; i++) {
			graph.add(new ArrayList<>());
		}
		// 1-2. 간선 개수만큼 간선 정보 추가
		int start, end;
		for (int i = 0; i < M; i++) {
			start = sc.nextInt();
			end = sc.nextInt();
			
			graph.get(start).add(end);
		}
		
		// 2. bfs로 거리가 K인 도시 구하기
		bfs(X);
		
		// 3. 거리가 K인 모든 도시 출력
		for (int i = 1; i <= N; i++) {
			if (distance[i] == K + 1) {
				System.out.println(i);
				isExist = true;
			}
		}
		if (!isExist) {
			System.out.println(-1);
		}

	}

	private static void bfs(int source) {
		distance = new int[N + 1];
		queue = new int[N];
		int front = -1, rear = -1;
		
		queue[++rear] = source;
		distance[source] = 1; // int는 0으로 초기화 되어 있으니 distance == K + 1인 곳을 찾도록 하자 일단.
		
		int v, w;
		while (front != rear) {
			v = queue[++front];
			
			for (int i = 0; i < graph.get(v).size(); i++) {
				w = graph.get(v).get(i);
				if (distance[w] == 0) {
					distance[w] = distance[v] + 1;
					queue[++rear] = w;
				}
			}
		}
	}
}

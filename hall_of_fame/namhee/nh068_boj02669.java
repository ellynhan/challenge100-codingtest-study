// boj2669 직사각형 네개의 합집합의 면적 구하기 (10분 + 5분)
package com.algo.practice.boj;

import java.util.Scanner;

public class nh068_boj02669 {
	
	static int[][] area = new int[101][101];
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		for (int rect = 0; rect < 4; rect++) 
		{
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			
			for (int X = x1; X < x2; X++) {
				for (int Y = y1; Y < y2; Y++) {
					area[X][Y] = 1;
				}
			}			
		}
		
		int answer = 0;
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				if (area[i][j] == 1)
					answer++;
		
		System.out.println(answer);

	}
}

/* 문제 이해
 * 서로 다른 직사각형(nxm) 4개. 축에 변이 평행.
 * 직사각형들은 떨어져 있을 수도, 겹쳐 있을 수도, 다른 하나를 포함 상태에 있을 수도 있으며,
 * 변 또는 꼭짓점이 겹칠 수도 있다.
 * 직사각형이 차지하는 면적 구하기
 * 입력
	> 직사각형의 위치를 나타내는 네 개의 정수 (x1, y1, x2, y2) * 4번
 */

/* 교수님 풀이
	//boj 2669 직사각형 네개의 합집합의 면적 구하기
	//-> 각각의 좌표를 이용해서 전체 넓이에서 겹치는 면적 일일이 빼려고 하면 끝이 없음.
	//주어진 좌표를 2차원 배열로 하여 주어진 사각형 정보를 이용해 넓이를 1로 표기하는 게 좋다.
	//--> ㅠ ㅠ ㅠ 이거 진짜 생각도 못했다
*/
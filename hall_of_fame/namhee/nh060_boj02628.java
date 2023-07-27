// boj2628 종이자르기 (16:25~17:00, 17:15~17:35)
package com.algo.practice.boj;

import java.util.Arrays;
import java.util.Scanner;

public class BOJ2628 {
	
	static int[] wLine = new int[100];
	static int[] hLine = new int[100];
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		int N = sc.nextInt();
		int wLineCount = 0;
		int hLineCount = 0;
		for (int i = 0; i < N; i++) {
			int val = sc.nextInt();
			if (val == 0) {
				wLine[++wLineCount] = sc.nextInt();
			}
			else if (val == 1) {
				hLine[++hLineCount] = sc.nextInt();
			}
		}

		Arrays.sort(wLine, 0, wLineCount+1);
		Arrays.sort(hLine, 0, hLineCount+1);
		
		int wMax = 0;
		for (int i = 0; i < hLineCount; i++) {
			wMax = Math.max(wMax, hLine[i+1] - hLine[i]);
		}
		wMax = Math.max(wMax, w - hLine[hLineCount]);
		
		int hMax = 0;
		for (int i = 0; i < wLineCount; i++) {
			hMax = Math.max(hMax, wLine[i+1] - wLine[i]);
		}
		hMax = Math.max(hMax, h - wLine[wLineCount]);
		
		int maxArea = wMax * hMax;
		System.out.printf("%d", maxArea);
	}
}

/* 문제 이해
 * 직사각형, 위->아래, 왼쪽->오른쪽으로 "선"에 번호가 있음. (칸은 선 개수+1)
 * 점선이 그여졌을 때 생긴 잘라진 종이들의 한 변의 길이 구하는 방법
	0, 점선 번호, N -> 큰 선 번호 - 작은 선 번호
 * 위와 같은 방식으로 구한 변의 길이의 최댓값을 곱하면 될 것이다.
 * 입력
	> 직사각형 가로, 세로
	> 가를 점선의 개수 N (입력받은 점선 정보)
	> 0 no or 1 no * (N회) 0이면 가로, 1이면 세로, no는 점선 번호
 */

/* 문제 설계 
 * 구해야 하는 것 : 가장 큰 종이 조각의 넓이 구하기 = 잘려진 가로변과 세로변의 최댓값의 곱 구하기
	0. 변수 선언
		int[][] line (최대 크기 100, 100로 선언)
		-> 가독성을 위해 수정함. wLine, hLine
 	1. 데이터 입력
 		> 가로, 세로 (w, h)
 		> 점선 개수 (N)
 		> for in N : 가로/세로(0/1), no(점선 번호) !!주의 : 순서가 항상 옳진 않다!
 			line 가로, 세로 점선 개수 구해서 이후 탐색에 사용하기
 			line[][] 에 저장.
 	2. 최댓값 구하기
 	for in <= 가로선개수 : (인덱스 0에는 0값을 써야 하기 때문)
 	가로선 개수 + 1만큼 연산이 발생해야 함 ㅇㅇ
 	0 - 처음가로선
 	처음가로선 - 마지막 가로선
 	마지막가로선 - N
 */

// 주의!! 세로선의 정보로 가로변의 최대를 구해야 하고, 가로선의 정보로 세로변의 최대를 구해야 한다!!!!

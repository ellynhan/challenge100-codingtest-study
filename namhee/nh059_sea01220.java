// 1220. [S/W 문제해결 기본] 5일차 - Magnetic (16:36~17:22 (45분)
// 기본 유형이라 for문과 적절한 자료구조를 쓰는 것에 집중합니다!
package com.algo.day02.swea;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class SWEA1220 {
	
	static int[][] table;

	static int getStateNum(int j, int size) {
		int num = 0;
		
		boolean isStarted = false;
		for (int i = 0; i < size; i++) {
			if (isStarted == false && table[i][j] == 1) {
				isStarted = true;
			}
			else if (isStarted == true && table[i][j] == 2) {
				isStarted = false;
				num++;
			}
		}
		
		return num;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("res/swea1220_input.txt"));	
		Scanner sc = new Scanner(System.in);
		int T = 10;
		
		// 1. 데이터(한변의 길이) 입력 후 배열 생성

		for(int test_case = 1; test_case <= T; test_case++)
		{			
			int size = sc.nextInt();
			table = new int[size][size];			
			// table 정보 (1-N극 성질(아래로), 2-S극 성질(위로)) 
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					table[i][j] = sc.nextInt();
			
			// 2. 교착 상태 개수 구하기 - 열 우선 탐색
			// 	  = (1, 2) 순서쌍 개수 구하기
			int num = 0;
			for (int j = 0; j < size; j++)
				num += getStateNum(j, size);
			
			// 3. 교착 상태의 개수 출력
			System.out.printf("#%d %d%n", test_case, num);
		}
	}
}

/* 문제 이해(쓰면서 이해하는 단계)
 * 푸른 자성체 : N극으로 이동하려는 성질이 있음.
 * 붉은 자성체 : S극으로 이동하려는 성질이 있음.
 * 교착 상태 : 일정 간격을 두고 강한 자기장을 걸었을 때, 시간이 흐른 뒤에 자성체들이 서로 충돌해...
 	-> 반대 방향으로 움직이는 자성체가 하나라도 있으면 교착 상태에 빠져 움직이지 않는다.
 	-> 즉, 숫자에 상관없다 부딪히면 그대로 멈춘다.
 * 같은 열에 같은 자성체만 있다면, 교착 상태에 빠지지 않는다.
 * 다른 자성체가 있다면, 교착 상태에 빠지는데 이는 서로 이동할 수 없어 멈춰버렸기 때문이다.
	-> 열이 기준이라 열 탐색을 하는 게 좋을 듯 하다
	
 * "교착 상태" : 다른 성질의 자성체가 접촉하면 그대로 멈춤. 이동X 그 뒤에 잇따라 오는 것도 멈춤.
	R/B/R/B -> 2개의 교착 상태
	R/R/B/B -> 1개의 교착 상태
	즉, R/B의 쌍의 개수가 한 열의 교착 상태의 개수라고 볼 수 있다.

 * Point : 구하고자 하는 것은 "교착상태의 개수"임을 잊지 말자. 교착상태가 어떻게 만들어지는지 출력하는 게 아니다.
 */

// Error1 : 논리 오류!! case마다 size값을 받아야 하는데 size값 받는 함수가 T밖에 있다!!
// ㅠㅠㅠㅠ 아니 세상에 이런 실수를 하다니 ㅠㅜㅠㅜㅠ
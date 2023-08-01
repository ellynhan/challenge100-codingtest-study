// boj 1339 단어 수학 (20:07 ~ 21:00, 
package com.algo.week01;

import java.util.Arrays;
import java.util.Scanner;

public class nh067_boj01339 {
	
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		int[] alphabet = new int[26];
		for (int i = 0; i < N; i++) 
		{
			String str = sc.nextLine();
			for (int j = str.length() - 1; j >= 0; j--) 
			{
				alphabet[str.charAt(j) - 'A'] 
						+= (int) Math.pow(10, str.length() - j - 1);
			}
		}
		
		Arrays.sort(alphabet);
		int sum = 0;
		int num = 9;
		for (int i = 25; i > 25 - 10; i--) {
			if(alphabet[i] == 0) break;
			
			sum += num * alphabet[i];
			num--;
		}
		
		System.out.println(sum);
	}
}

/* 문제 이해
	알파벳 대문자로만 이뤄진 N개의 단어
	대문자 한 개당 0~9로 변경 (각 알파벳은 숫자 하나와 유일하게 매칭)
	주어진 단어의 합의 최댓값을 구하라.

	합이 최대가 되려면, 자릿수가 큰 값의 알파벳이 큰값을 가져야 한다.

	문제는 같은 길이의 문자가 있을 때는 어떻게 처리하느냐이다.
	
	수의 최대 길이가 8이며, 단어의 최대 개수는 10개이므로 int 써도 됨.
 */

/* 문제 재정의
 	다음 배열을 이용해서 근거로 삼아서 알파벳을 할당하면 어떨까
 	(A~J만 순서대로 들어온다는 보장은 없는 것 같아서)
 	알파벳 char[] alpha = char[10]
 	1. 각 자릿수에 몇개 씩 있는지 체크
 	  		0 1 2 3 4 5 6 7 8
alpha[0] A 
 		B
 		C
 		D
 		E
 		F
 		G
 		H
 		I
 		J
 	2. 자릿수 8부터 순서대로 많은 것부터 숫자 할당해 
 		값을 곱한다.
 		만약 여기서 결정되지 않는다면...? -> 모르겠군...^^
 	3. 각 자릿수마다 단어만큼 확인됐다면 다음으로 넘어간다.
 	4. 
 */

/* TEST CASE 
 	3
 	ABC
 	CAA
 	BBC
 	
 	답) 2682 (B = 9, A = 8, C = 7)
 */
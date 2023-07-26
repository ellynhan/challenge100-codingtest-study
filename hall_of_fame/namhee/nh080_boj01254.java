// boj1254 팰린드롬 만들기 (21:00 ~ 21:21)


import java.util.Scanner;

public class nh080_boj01254 {

	static String S;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		S = sc.next();
		
		int addLen = 0;
		while(true) {
			if (check(addLen)) break;
			addLen++;
		}
		
		int Answer = S.length() + addLen;
		System.out.println(Answer);
	}

	private static boolean check(int addLen) {
		// 1. 앞 문자부터 차례대로 붙이기
		String tmp = S;
		int addIndex = addLen;
		while(addIndex-- > 0) {
			tmp += S.charAt(addIndex);
		}
		
		// 2. 팰린드롬 체크
		int len = tmp.length();
		for (int i = 0; i < len / 2; i++) {
			if (tmp.charAt(i) != tmp.charAt(len - 1 - i))
				return false;
		}
		
		return true;
	}
}

// qwti라는 단어가 있다면
// q, wq, twq 이렇게 뒤에 더해보고 체크해야 한다 그러면,
// 0 		(addLen : 1)
// 1 0 		(addLen : 2)
// 2 1 0	(addLen : 3) 
// (addLen - 1) 에서 0 index까지 순서대로 더해줘야 최소 길이를 찾을 수 있다.
// boj4949 균형잡힌 세상 (02:00 ~ 02:25)


import java.util.Scanner;

public class nh081_boj04949 {
	
	static char[] stack = new char[100];
	static int top;
	static String str;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String Answer;
		while (true) {
			str = sc.nextLine();
			if (str.equals(".")) break;
			
			Answer = check();
			
			System.out.println(Answer);
		}
	}

	private static String check() {
		top = -1;
		char ch;
		
		for (int i = 0; i < str.length(); i++) {
			ch = str.charAt(i);
			
			if (ch == '(' || ch == '[')	{
				stack[++top] = ch;
			}
			else if (ch == ')') {
				if (top < 0 || stack[top--] == '[') return "no";
			}
			else if (ch == ']') {
				if (top < 0 || stack[top--] == '(') return "no";				
			}
		}
		if (top > -1) return "no";
		
		return "yes";
	}
}

// 괄호의 균형이 잘 맞는지 판단하는 프로그램을 짜보자. (기준은 아래와 같다.)
// 1. '('은 ')'와 짝을 이뤄야 한다.
// 2. '['은 ']'와 짝을 이뤄야 한다.
// 3. 1:1 매칭이어야만 한다.
// 4. 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다. -> 이게 대체 뭔 소리?
// -> TC만으로는 유추하기 힘든 것 같다... -> 그냥 괄호만 신경쓰면 되는듯 하다 ㅠㅠ 괜히 이것땜에 몇분 날렷네...

// "입력의 종료조건" : '.'
// nextLine의 값이 '.'이라면 종료하자. (앞에 빈칸이 있는 경우도 안 된다. 예 : ' .')

// 괄호는 stack으로 처리한다. 왼쪽 괄호는 조건 없이 push
// 오른쪽 괄호는 top이 자신과 같은 종류일 때만 pop 가능 / pop이 불가하면 no 출력, stack 크기가 0 이상이어도 no


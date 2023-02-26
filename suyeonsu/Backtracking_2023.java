import java.util.*;

public class Main {
	static int n;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for(int i=2; i<=7; i++)
			dfs(i, 1);
		System.out.println(sb);
	}
	
	private static void dfs(int num, int digit) {
		if(!isPrime(num)) return;
		if(digit == n) {
			sb.append(num + "\n");
			return;
		}
		for(int i=1; i<=9; i+=2) {
			dfs(num*10 + i, digit+1);
		}
	}
	
	private static boolean isPrime(int num) {
		if(num == 1) return false;
		if(num == 2) return true;
		for(int i=2; i*i<=num; i++) {
			if(num%i == 0) return false;
		}
		return true;
	}
}

/**
 * 메모리 초과의 원인
 * - 배열 크기가 너무 클 때
 * - 스택 영역에 함수가 너무 많을 때 (보통 재귀 함수로 호출이 많아졌을 때)
 * - 자료구조에 너무 많은 데이터가 들어가있을 때
 * */

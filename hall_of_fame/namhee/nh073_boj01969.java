// boj 1969 DNA (1시간 20분)
package com.algo.week04;

import java.util.Scanner;

public class BOJ1969 {
	
	static String[] dna;
	static int[] A;
	static int[] C;
	static int[] G;
	static int[] T;
	static int N, M;
	static String s;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		dna = new String[N];
		for (int i = 0; i < N; i++) {
			dna[i] = sc.next();
		}
		
		A = new int[M];
		C = new int[M];
		G = new int[M];
		T = new int[M];
		count();
		
		createS();
		
		int hdSum = getHammingDistanceSum();
	
		System.out.println(s);
		System.out.println(hdSum);
	}

	private static int getHammingDistanceSum() {

		int hdSum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {				
				if (dna[i].charAt(j) != s.charAt(j))	hdSum++;
			}
		}	
		return hdSum;
	}

	private static void count() {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char ch = dna[i].charAt(j);

				if (ch == 'A')		A[j]++;
				else if (ch == 'C')	C[j]++;
				else if (ch == 'G')	G[j]++;
				else if (ch == 'T')	T[j]++;

			}
		}		
	}

	private static void createS() {
		char[] charArray = new char[M];
		
		for (int i = 0; i < M; i++) {
			if (A[i] >= C[i] && A[i] >= G[i] && A[i] >= T[i]) {
				charArray[i] = 'A';
			}
			else if (C[i] >= G[i] && C[i] >= T[i]) {
				charArray[i] = 'C';
			}
			else if (G[i] >= T[i]) {
				charArray[i] = 'G';
			}
			else {
				charArray[i] = 'T';
			}
		}
		
		s = String.valueOf(charArray);
	}

}

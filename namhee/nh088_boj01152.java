// boj1152 단어의 개수 (20:30 ~ 20:40)
// Scanner (544ms) vs. BufferedReader (264ms)

import java.io.BufferedReader;
import java.io.InputStreamReader;
// import java.util.Scanner;

public class nh088_boj01152 {

	public static void main(String[] args) throws Exception {
		
		// Scanner sc = new Scanner(System.in);
		// String str = sc.nextLine();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		if (str.equals(" ")) { // str이 빈칸만 있는 상황을 고려해주어야 한다.
			System.out.println(0);
		}
		else {
			String[] word = str.split(" ");

			if (word[0].equals("")) {
				System.out.println(word.length - 1);
			} 
			else {
				System.out.println(word.length);			
			}
		}
	}
}

/*
	if (word[0].equals("")) {
		System.out.println(word.length - 1);
	} else {
		System.out.println(word.length);			
	}
	
	-> 이렇게 작성하면, 빈칸이 하나일 때 ArrayIndexOutOfBounds가 발생한다.
 */

// boj2941 : LJESNJAK (1시간)
import java.util.Scanner;

public class nh100_boj02941 {

	static String[] croatians = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	
	public static void main(String[] args) {
		// 1. INPUT
		Scanner sc = new Scanner(System.in);
		String word = sc.next();
		
		// 2. GET NUM OF LETTERS
		int num = 0;
		// Compare
		for (int index = 0; index < word.length(); index++) {
			if (index < word.length() - 1) {
				// with croatian alphabet array
				for (int i = 0; i < croatians.length; i++) {
					// check impossible length
					if (index + croatians[i].length() > word.length() ) { continue; }
					
					// check same croatian
					if (word.substring(index, index + croatians[i].length()).equals(croatians[i])) {
						//System.out.println("SubString[" + index + "] : " + word.substring(index, index + croatians[i].length()));
						index += (croatians[i].length() - 1);
						break;
					}
				}				
			}
			num++;
		}

		// 3. OUTPUT
		System.out.println(num);
	}
}

// Programmers agreed to use 2 or 3-letter substitutions

// 비교 알고리즘
// input data 특징 : 글자 길이가 최대 100개 (길이가 작다.)
// 오직 lowercase + '-' + '='만 존재 (= 굳이 다른 작업 할 필요 X)

// 크로아티안 특징, 2글자는 물론, 3글자가 하나의 단어가 될 수도 있다.


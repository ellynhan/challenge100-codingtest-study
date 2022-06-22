import java.util.Scanner;

public class nh095_boj10808 {
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		
		int[] alphabet = new int[26];		
		for (int i = 0; i < str.length(); i++) {
			alphabet[str.charAt(i) - 'a']++;
		}
		
		for (int i = 0; i < alphabet.length; i++) {
			System.out.print(alphabet[i] + " ");
		}
	}
}

// alphabet[i] + ' '로 작성하는 바람에 (-> char로 인식한듯)
// 출력 결과가 32로 나와서 예상한 결과가 나오지 않았다!

// alphabet[i] + " "으로 작성해야 한다!

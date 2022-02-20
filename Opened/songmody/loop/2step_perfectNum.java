import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		String input = br.readLine();
		
		Scanner sc = new Scanner(System.in);
		int startNum = sc.nextInt();
		int endNum = sc.nextInt();
		int result = 0;
		String resString ="";
		
		for(int i = startNum; i<=endNum; i++){
			for(int k = 1; k < i; k++){
				if(i % k == 0){
					result += k;
				}
			}
			// System.out.println("i: "+ i+ "res: " +result);
			if(result == i){
				resString += result + " "; 
			}
			result = 0;
		}
		System.out.println(resString);
	}
}

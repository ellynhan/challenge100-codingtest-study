import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// String input = br.readLine();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
			
		int res = n / m ;
		int navRes = n % m;
		int realRes = 0;
		
		if(navRes == 0 || res >= m){
			int navNum = res / m;
			realRes = n + res + navNum;	
		}else if(navRes + 1 == m){
			realRes = n + res + 1;
		}else{
			realRes = n + res;
		}
			System.out.println(realRes);
	}
}

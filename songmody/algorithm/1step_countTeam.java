import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		int result = 0; 
		
		for(int i = 1; i<input; i++){
			result += i;
		}
		System.out.println(result);
	}
}

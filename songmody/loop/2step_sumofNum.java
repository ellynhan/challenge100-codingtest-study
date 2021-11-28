import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		int inNum = Integer.parseInt(input);
		int sum = 0;
		
		for(int i = 1; i<= inNum; i++){
			if(inNum % i == 0){
				sum += i;
			}
		}
		System.out.println(sum);
	}
}

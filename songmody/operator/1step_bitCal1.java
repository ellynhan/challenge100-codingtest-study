import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] inputList = input.split(" ");
		
		int firstNum = Integer.parseInt(inputList[0]);
		int secNum = Integer.parseInt(inputList[1]);
		
		System.out.println(firstNum & secNum);	
		System.out.println(firstNum | secNum);
		System.out.println(firstNum ^ secNum);
	
	}
}

import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] inputList = input.split(" ");
		
		int firstNum = Integer.parseInt(inputList[0]);
		int secondNum = Integer.parseInt(inputList[1]);
		
		int res = firstNum % secondNum ;
		int resOth = firstNum / secondNum;
		
		System.out.println(resOth + " " + res);
		
	}
}

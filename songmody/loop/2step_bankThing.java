import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] inputList = input.split(" ");
		
		int money = Integer.parseInt(inputList[0]);
		double perNum = Double.parseDouble(inputList[1]);
		int year = Integer.parseInt(inputList[2]);
		double result = 0;
		
		for(int k = 1; k <= year; k++){
			result += (money + result) * (perNum * 0.01);
			// System.out.println("result"+ k + ": " + result);
		}
		
		System.out.println(String.format("%.2f", money + result));
	}
}

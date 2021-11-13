import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		String[] inputList = input.split(" ");
		int firstNum = Integer.parseInt(inputList[0]);
		int secondNum = Integer.parseInt(inputList[2]);
		String cal = inputList[1];
		int result = 0;
		
		switch(cal){
			case "+": 
				result = firstNum + secondNum;
				System.out.println(result);
				break;
			case "-": 
				result = firstNum - secondNum; 
				System.out.println(result);
				break;
			case "/": 
				result = firstNum / secondNum; 
				System.out.println(String.format("%.2f", (double)result));
				break;
			case "*": 
				result = firstNum * secondNum; 
				System.out.println(result);
				break;
		}
	}
}

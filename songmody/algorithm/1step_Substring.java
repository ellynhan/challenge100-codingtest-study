import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String cutNum = br.readLine();
		
		String[] inputList = cutNum.split(" ");
		int firstNum = Integer.parseInt(inputList[0]);
		int secondNum = Integer.parseInt(inputList[1]);
		
		String result = input.substring(firstNum-1, firstNum+secondNum-1);
		System.out.println(result);
	}
}

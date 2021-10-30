import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] inputList = input.split(" ");
		
		int a = Integer.parseInt(inputList[0]);
		int b = Integer.parseInt(inputList[1]);
	
		int temp = a >> b;
		int temp2 = a << b;
		System.out.println(temp);
		System.out.println(temp2);
	}
}

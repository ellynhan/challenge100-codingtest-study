import java.io.*;
class Main {
	
	static int result,res = 0;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		String[] inputList = input.split(" ");
		
		int firstNum = Integer.parseInt(inputList[0]);
		int secNum = Integer.parseInt(inputList[1]);
		
		res = Min(firstNum, secNum);
		System.out.println(res);
	}
	
	public static int Min(int firstNum, int secNum){
			if(firstNum > secNum){
				result = secNum;
			}else {
				result = firstNum;
			}
			return result;
		}
}

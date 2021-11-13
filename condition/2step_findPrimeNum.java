import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		int inNum = Integer.parseInt(input);
		boolean result = false;
		
		for(int i = 2; i < inNum; i++){ 
			if(inNum % i == 0){	//자기자신과 1로만 나눌 수 있는 수 = 소수;
				result = true; //소수가 아닌겨
				break;
			}
		}
		
		if(result){
			System.out.println("False");
		}else{
			System.out.println("True");
		}
	}
}

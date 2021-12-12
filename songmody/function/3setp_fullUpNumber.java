import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine()); 	//765 -> 567
		int res = 0;
		
		while(input != 0){
			res = res * 10 + input % 10;	//5 //6 //7
			input = input / 10;
		}
		System.out.println(res);
	}
}

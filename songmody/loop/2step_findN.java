import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		int res = 0;
		int resNum = 0;
		
		for(int i = 1; i < input; i++){
			res += i;
			if(res>input){
				resNum = i;
				break;
			}
		}
		System.out.println(resNum);
	}
}

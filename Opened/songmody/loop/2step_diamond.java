import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		
		for(int i = 1; i<=input/2; i++){
			for(int j = input/2-i; j>=0; j--){
				System.out.print(" ");
			}
			for(int k = 1; k<2*i; k++){
				System.out.print("*");
			}
			System.out.println();
		}
	
	if(input % 2 != 0){
		for(int n = 0; n < input; n++){
			System.out.print("*");
		}
		System.out.println();
	}
	for(int i = input/2; i>0; i--){ //3,2,1
		for(int j = input/2-i; j>=0; j--){
			System.out.print(" ");
		}
		for(int k = (i*2)-1; k > 0; k--){
			System.out.print("*");
		}
		System.out.println();
	}
	}
}

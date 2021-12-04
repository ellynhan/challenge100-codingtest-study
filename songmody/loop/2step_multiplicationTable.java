import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		
		for(int i = 2; i<10; i++){
			for(int k =1; k<10; k++){
				
				System.out.print(i + " * " + k + " = " + i * k + " ");
				if(k % input == 0){	//input : 3, 
					System.out.println();
				}
			}
		}
		
	}
}

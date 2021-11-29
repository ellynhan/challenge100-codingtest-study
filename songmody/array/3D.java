import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
	int[][][] arr = new int[3][3][3];
	int num = 1;
		
		for(int k = 0; k < arr.length; k++){
			for(int j = 0; j< arr[k].length; j++){
				for(int i = 0; i < arr[k][j].length; i++){
					System.out.print(num+" ");
					num++;
				}
				System.out.println();
			}
			System.out.println();
		}
		
	}
}

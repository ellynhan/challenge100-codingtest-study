import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		
		String arr = br.readLine();
		String[] inputList = arr.split(" ");
		for(int i = 0; i<inputList.length-1; i++){ 
			for(int j = i + 1; j<inputList.length; j++){
				String num = inputList[i];
					if(Integer.parseInt(inputList[i]) > Integer.parseInt(inputList[j])){	
						inputList[i] = inputList[j];	
						inputList[j] = num;	
					} 
			}
		}
		
		for(int k = 0; k<inputList.length; k++){
				System.out.print(inputList[k] + " ");
			}

	}
}

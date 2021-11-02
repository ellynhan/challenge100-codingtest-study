import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String parse = br.readLine();
		int count = 0;
		String[] inputList = input.split("");
		
			for(int k = 0; k<inputList.length; k++){
				if(inputList[k].equals(parse)){
					count +=1;
				}
			}
		System.out.println(count);
		
	}
}

import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		int max = 0;
		
		String secInput = br.readLine();
		String[] secList = secInput.split(" ");
		
		for(int i = 0; i < secList.length-1; i ++){
			if(Integer.parseInt(secList[i]) < Integer.parseInt(secList[i+1])){
				max = Integer.parseInt(secList[i+1]);
			}else{
				int num = Integer.parseInt(secList[i]);
				secList[i+1] = Integer.toString(num);
				max = num;
			}
		}
		System.out.println(max);
	}
}

import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		int count = 0;
		
		
		for(int i = 1; i < Integer.parseInt(input); i++){
			String[] inputList = String.valueOf(i).split("");
			int length = inputList.length;			
			
			for(int k = 0; k < length; k++){
				if(inputList[k].contains("3") || inputList[k].contains("6") || inputList[k].contains("9")){
					count+=1;
				}
			}
		}	
		System.out.println(count);
	}
}

import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		
		String dot = br.readLine();
		String[] dotList = dot.split(" ");
		int compareNum = 0;
		int minNum = 1000000;
		
		for(int i = 0; i < dotList.length -1 ; i++){
			compareNum = Integer.parseInt(dotList[i+1]) - Integer.parseInt(dotList[i]);
			if(minNum > compareNum){
				minNum = compareNum;
			}else{
				minNum = minNum;
			}
		}
		System.out.println(minNum);
	}
}

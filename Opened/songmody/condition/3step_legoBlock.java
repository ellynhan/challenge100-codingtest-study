import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		String[] topList = br.readLine().split(" ");
		int leftCnt = 0;
		int rightCnt = 0;
		int val = 0;
		
		for(int i = 0; i < topList.length; i++){
			if(val < Integer.parseInt(topList[i])){
				val = Integer.parseInt(topList[i]);
				leftCnt = leftCnt + 1;
			}
		}
		
		val = 0;
		
		for(int i = topList.length-1; i >= 0; i--){
			if(val < Integer.parseInt(topList[i])){
				val = Integer.parseInt(topList[i]);
				rightCnt = rightCnt + 1;
			}
		}
		// System.out.println(leftCnt);
		
		System.out.println(leftCnt + " "+ rightCnt);
	}
}

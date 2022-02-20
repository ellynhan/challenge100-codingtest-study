import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		//처음 푼거,, 무작정 풀지말고 공식이 존재할 수 있는 수학 문제인지 생각해보자. 
// 		Scanner sc = new Scanner(System.in);
// 		int a = sc.nextInt();
// 		int b = sc.nextInt();
// 		int c = sc.nextInt();
// 		double secRes = 0 ;
// 		double alpha = 0;
// 		double beta = 0;
		
// 		for(int i=-c; i<0; i++){
// 			alpha = (c/i);
// 				if((c % i) == 0 && alpha + i == b){
// 					if(i == alpha){
// 						secRes = -alpha;
// 					}else{
// 						beta = -i;
// 						secRes = -alpha;
// 					}
// 				}
// 			}
		
// 		for(int i=1; i<=c; i++){
// 			alpha = (c/i);
// 				if((c % i) == 0 && alpha + i == b){
// 					if(i == alpha){
// 						secRes = -alpha;
// 					}else{
// 						beta = -i;
// 						secRes = -alpha;
// 					}
// 				}
// 			}
		
// 		if(beta == 0.0){
// 			System.out.println(String.format("%.2f", secRes));
// 		}else{
// 			System.out.println(String.format("%.2f", secRes) + ", " + String.format("%.2f", beta));
// 		}
		
		//시간이 너무 오래 걸리는데,, 다른 방법없나? -> wow근의공식,,???
	
			Scanner sc = new Scanner(System.in);
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			double firstX = 0;
			double secX = 0;
		
			firstX = (-b + Math.sqrt(b*b - 4*a*c)) / (2*a);
			secX = (-b - Math.sqrt(b*b - 4*a*c)) / (2*a);
		
			if(b*b - 4*a*c < 0){
				System.out.println("X");
			}	else if(firstX == secX){
				System.out.println(String.format("%.2f", firstX));
			}else{
				System.out.println(String.format("%.2f",firstX) + ", " + String.format("%.2f", secX));
			}
	}
}

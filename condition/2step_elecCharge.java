import java.io.*;
//5min
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = Integer.parseInt(br.readLine());
		double res = 0;
		if(input < 100){
			res = input * 0.005;
		}else if(input < 200){
			res = input * 0.007;
		}else if(input < 300){
			res = input * 0.009;
		}else{
			res = input * 0.01;
		}
		System.out.println(String.format("%.2f", res));
	}
}

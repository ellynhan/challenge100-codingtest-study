import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_2839 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int result=0;
        while(true) {
            if(n%5==0) {
                result += n/5;
                System.out.println(result);
                break;
            }
            else {
                n-=3;
                result++;
            }
            if(n<0) {
                System.out.println("-1");
                break;
            }
        }




    }
}
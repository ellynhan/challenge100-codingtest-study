import java.io.*;
class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int input = Integer.parseInt(br.readLine());
        int result = 0;

        for(int i = 1; i <= input; i++){
            if(i % 3 == 0 || i % 5 == 0){
                result += i;
            }
        }
        System.out.println(result);
    }
}

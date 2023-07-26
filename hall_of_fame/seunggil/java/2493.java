import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(re.readLine());
        int[][] inputData = new int[n][2];
        StringTokenizer token = new StringTokenizer(re.readLine());
        StringBuilder result = new StringBuilder();
        re.close();

        for(int i = 0; i < n; i++){
            inputData[i] = new int[2];
        }

        int index = 1;
        inputData[0][0] = Integer.parseInt(token.nextToken());
        inputData[0][1] = 1;

        result.append("0 ");
        for (int i = 1; i < n; i++) {
            inputData[index][0] = Integer.parseInt(token.nextToken());
            int j = index -1;
            while(j > -1 && inputData[j][0] < inputData[index][0]){
                j--;
            }
            // 값 출력
            if(j == -1){
                result.append("0 ");
            }else{
                result.append(inputData[j][1]);
                result.append(' ');
            }

            j++;
            inputData[j][0] = inputData[index][0];
            inputData[j][1] = i+1;
            index = j+1;
        }

        wr.write(result.toString());
        wr.close();
    }
}

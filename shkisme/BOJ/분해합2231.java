
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static void main(String[] args) throws IOException {
    new Main().solution();
  }

  public void solution() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = Integer.parseInt(br.readLine());
    int constructor = 0; // 생성자가 없을 경우 0을 출력하기 위해, 초기화를 0으로 해준다.
    for (int i = 1 ; i <= N; i++){
      int result = i; // 결과에 자기 자신을 먼저 더한다.
      String intToString = String.valueOf(i); // 문자열로 변환하고
      for (int j = 0; j < intToString.length(); j++){
        result += Character.getNumericValue(intToString.charAt(j)); // 각 자릿수의 값을 결과에 더한다.
      }

      if (result == N) { // 결과가 N과 같다면, 생성자이다!
        constructor = i;
        break;
      }
    }
    bw.write(String.valueOf(constructor));
    bw.flush();
  }
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

  public static final HashMap<Integer, Boolean> isPrime = new HashMap<>();
  private static final int maxNum = 1000;
  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  public static void main(String[] args) throws IOException {

    makePrime(maxNum + 1);

    int T = getTestCase();

    List<Integer> inputNumList = getInputNumList();

    long primeCount = getPrimeCount(inputNumList);

    bw.write(String.valueOf(primeCount));

    bw.flush();
    br.close();
    bw.close();
  }

  private static long getPrimeCount(List<Integer> inputNumList) {
    return inputNumList.stream().filter(isPrime::get).count();
  }

  private static List<Integer> getInputNumList() throws IOException {
    return Arrays.stream(br.readLine().split(" "))
        .map(Integer::parseInt).collect(Collectors.toList());
  }

  private static int getTestCase() throws IOException {
    return Integer.parseInt(br.readLine());
  }

  public static void makePrime(int maxNum) {

    if (maxNum < 2) {
      return;
    }

    isPrime.put(0, false);
    isPrime.put(1, false);

    for (int num = 2; num <= maxNum; num++) {
      if (isPrime.get(num) != null && !isPrime.get(num)) {
        continue;
      }

      isPrime.put(num, true);
      for (int nonPrimeNum = num * num; nonPrimeNum < maxNum; nonPrimeNum += num) {
        isPrime.put(nonPrimeNum, false);
      }
    }
  }
}

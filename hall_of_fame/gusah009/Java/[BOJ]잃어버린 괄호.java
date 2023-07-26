import static java.lang.Character.isDigit;
import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

  private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  private static final List<Character> operatorList = new ArrayList<>();
  private static final List<Integer> operandList = new ArrayList<>();

  private static class DP {

    private final int[][] dpArr; // [i:j]

    public DP(int maxCount) {
      this.dpArr = new int[maxCount][maxCount];
    }

    public void set(int startRange, int endRange, int value) {
      if (startRange > endRange) {
        return;
      }
      dpArr[startRange][endRange] = value;
    }

    public int get(int startRange, int endRange) {
      if (startRange > endRange) {
        return 0;
      }
      return dpArr[startRange][endRange];
    }
  }

  public static void main(String[] args) throws IOException {

    String expression = br.readLine().strip();

    parseExpression(expression);

    DP dpMax = new DP(operandList.size());
    DP dpMin = new DP(operandList.size());

    initDpArr(dpMax, dpMin);

    for (int size = 2; size <= operandList.size(); size++) {
      for (int i = 0; i <= operandList.size() - size; i++) {
        int maxResult = Integer.MIN_VALUE;
        int minResult = Integer.MAX_VALUE;
        for (int j = size - 1; j > 0; j--) {
          switch (operatorList.get(i + j - 1)) {
            case '+':
              maxResult = max(dpMax.get(i, i + j - 1) + dpMax.get(i + j, i + size - 1), maxResult);
              minResult = min(dpMin.get(i, i + j - 1) + dpMin.get(i + j, i + size - 1), minResult);
              break;
            case '-':
              maxResult = max(dpMax.get(i, i + j - 1) - dpMin.get(i + j, i + size - 1), maxResult);
              minResult = min(dpMin.get(i, i + j - 1) - dpMax.get(i + j, i + size - 1), minResult);
              break;
          }
        }
        dpMax.set(i, i + size - 1, maxResult);
        dpMin.set(i, i + size - 1, minResult);
      }
    }

    bw.write(String.valueOf(dpMin.get(0, operandList.size() - 1)));

    bw.flush();
    br.close();
    bw.close();
  }

  private static void initDpArr(DP dpMax, DP dpMin) {

    for (int i = 0; i < operandList.size(); i++) {
      dpMax.set(i, i, operandList.get(i));
      dpMin.set(i, i, operandList.get(i));
    }
  }

  private static void parseExpression(String expression) {
    for (int i = 0; i < expression.length(); i++) {
      switch (expression.charAt(i)) {
        case '+':
          operatorList.add('+');
          break;
        case '-':
          operatorList.add('-');
          break;
        default:
          int newOperand = 0;
          while (i < expression.length() && isDigit(expression.charAt(i))) {
            newOperand = newOperand * 10 + (expression.charAt(i) - '0');
            i++;
          }
          operandList.add(newOperand);
          i--;
          break;
      }
    }
  }
}

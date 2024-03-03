package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class NumberBaseball {

  static int N;
  static int result;
  static List<Input> inputs = new ArrayList<>();

  public static class Input {
    int number;
    int strike;
    int ball;

    public Input(int number, int strike, int ball) {
      this.number = number;
      this.strike = strike;
      this.ball = ball;
    }

  }

  public static class Number {

    int hundreds;
    int tens;
    int units;

    public Number(int number) {
      this.hundreds = number / 100;
      this.tens = number / 10 - (hundreds * 10);
      this.units = number % 10;
    }

    public boolean hasZero() {
      return hundreds == 0 || tens == 0 || units == 0;
    }

    public boolean hasSameNumber() {
      return hundreds == tens || hundreds == units || tens == units;
    }
  }


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    N = Integer.parseInt(br.readLine());

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      addInput(st);
    }

    for (int i = 123; i < 988; i++) {
      Number number = new Number(i);
      if (!number.hasZero() && !number.hasSameNumber() && checkPositive(number)) {
          result++;
      }
    }

    System.out.println(result);
  }

  public static void addInput(StringTokenizer st) {
    int number = Integer.parseInt(st.nextToken());
    int strike = Integer.parseInt(st.nextToken());
    int ball = Integer.parseInt(st.nextToken());

    inputs.add(new Input(number, strike, ball));
  }

  public static boolean checkPositive(Number number) {
    for (int i = 0; i < inputs.size(); i++) {
      Input input = inputs.get(i);
      Number check = new Number(input.number);

      int strike = strike(number, check);
      int ball = ball(number, check);

      if (input.strike != strike || input.ball != ball) {
        return false;
      }
    }
    return true;
  }

  public static int strike(Number number, Number check) {
    int count = 0;
    if (number.hundreds == check.hundreds) count++;
    if (number.tens == check.tens) count++;
    if (number.units == check.units) count++;
    return count;
  }

  public static int ball(Number number, Number check) {
    int count = 0;
    if (number.hundreds == check.tens || number.hundreds == check.units) count++;
    if (number.tens == check.hundreds || number.tens == check.units) count++;
    if (number.units == check.hundreds || number.units == check.tens) count++;
    return count;
  }

}

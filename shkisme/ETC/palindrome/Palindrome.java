package palindrome;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Palindrome {

  static int N;

  static List<String> strings = new ArrayList<>();

  static List<Integer> answers = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    input(br);
    solve();
    print();

    br.close();
  }

  private static void input(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; i++) {
      strings.add(br.readLine());
    }
  }

  private static void solve() {
    for (String string : strings) {
      Type type = judgePalindrome(string, new StringBuilder(string).reverse().toString());
      if (type == Type.Palindrome) {
        answers.add(Type.Palindrome.getValue());
      }
      if (type == Type.PseudoPalindrome) {
        answers.add(Type.PseudoPalindrome.getValue());
      }
      if (type == Type.Normal) {
        answers.add(Type.Normal.getValue());
      }
    }
  }

  private static Type judgePalindrome(String string, String reverse) {
    int length = string.length();
    if (string.equals(reverse)) {
      return Type.Palindrome;
    }
    for (int i = 0; i < string.length(); i++) {
      if (i == 0) {
        String newString = string.substring(1, length);
        String reverseNewString = new StringBuilder(newString).reverse().toString();
        if (newString.equals(reverseNewString)) {
          return Type.PseudoPalindrome;
        }
      } else if (i == string.length() - 1) {
        String newString = string.substring(0, length - 1);
        String reverseNewString = new StringBuilder(newString).reverse().toString();
        if (newString.equals(reverseNewString)) {
          return Type.PseudoPalindrome;
        }
      } else {
        String newString = string.substring(0, i) + string.substring(i + 1, length);
        String reverseNewString = new StringBuilder(newString).reverse().toString();
        if (newString.equals(reverseNewString)) {
          return Type.PseudoPalindrome;
        }
      }
    }
    return Type.Normal;
  }

  private static void print() {
    answers.forEach(System.out::println);
  }
}

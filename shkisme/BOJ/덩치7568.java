package 덩치7568;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

  static int N;

  static List<Person> people = new ArrayList<>();

  static List<Long> answer = new ArrayList<>();

  public static class Person {

    private final int weight;
    private final int height;

    public Person(int weight, int height) {
      this.weight = weight;
      this.height = height;
    }

    public int getWeight() {
      return weight;
    }

    public int getHeight() {
      return height;
    }
  }

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
      String[] s = br.readLine().split(" ");
      people.add(new Person(Integer.parseInt(s[0]), Integer.parseInt(s[1])));
    }
  }

  private static void solve() {
    for (int i = 0; i < N; i++) {
      Person person = people.get(i);
      long count = people.stream()
          .filter(p -> p.getWeight() > person.getWeight() && p.getHeight() > person.getHeight())
          .count();
      answer.add(++count);
    }
  }

  private static void print() {
    for (Long a : answer) {
      System.out.print(a + " ");
    }
  }
}

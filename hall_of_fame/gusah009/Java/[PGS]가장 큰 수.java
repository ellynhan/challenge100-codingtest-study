import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {

  public String solution(int[] numbers) {
    if (Arrays.stream(numbers).max().getAsInt() == 0) {
      return "0";
    }
    return Arrays.stream(numbers)
        .mapToObj(String::valueOf)
        .map(MyClass::new)
        .sorted()
        .map(s -> s.val)
        .collect(Collectors.joining());
  }

  class MyClass implements Comparable<MyClass> {

    String val;

    public MyClass(String val) {
      this.val = val;
    }

    @Override
    public int compareTo(MyClass o) {
      return (o.val + this.val).compareTo(this.val + o.val);
    }
  }
}
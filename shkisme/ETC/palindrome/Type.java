package palindrome;

public enum Type {
  Palindrome(1), PseudoPalindrome(2), Normal(3);
  private int value;

  Type(int value) {
    this.value = value;
  }

  public int getValue() {
    return value;
  }
}

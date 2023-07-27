class Solution {
  public int solution(int[] numbers) {
    boolean[] arr = new boolean[10];
    for (var number: numbers) {
      arr[number] = true;
    }

    int answer = 0;
    for (int i = 0; i < arr.length; i++) {
      if (!arr[i]) {
        answer += i;
      }
    }
    return answer;
  }
}

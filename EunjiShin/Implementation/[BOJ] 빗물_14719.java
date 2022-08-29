package Implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Rain {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");

    // 높이 길이 입력
    int height = Integer.parseInt(st.nextToken());
    int width = Integer.parseInt(st.nextToken());
    int result = 0;

    // 빗물이 찬 높이 입력
    int[] array = new int[width];
    st = new StringTokenizer(br.readLine(), " ");
    for (int i = 0; i < width; i++) {
      array[i] = Integer.parseInt(st.nextToken());
    }

    // 빗물 고인 부분 구하기
    for (int i = 0; i < width; i++) {
      int current = array[i];
      int leftMax = getLeftMax(array, i);
      int rightMax = getRightMax(array, i);
      if (leftMax > current && rightMax > current) result += Math.min(leftMax, rightMax) - current;
    }

    System.out.println(result);

  }

  // 왼쪽에서 제일 높은 친구 구하기
  private static int getLeftMax(int[] array, int index) {
    int max = 0;
    for (int i = 0; i < index; i++) {
      max = Math.max(max, array[i]);
    }
    return max;
  }

  // 오른쪽에서 제일 높은 친구 구하기
  private static int getRightMax(int[] array, int index) {
    int max = 0;
    for (int i = index + 1; i < array.length; i++) {
      max = Math.max(max, array[i]);
    }
    return max;
  }

}

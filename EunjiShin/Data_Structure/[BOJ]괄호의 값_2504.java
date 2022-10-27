package DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BracketValue {
  public static void main(String[] args) throws IOException {

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String str = bf.readLine();
    Stack<Character> stack = new Stack<>();
    int result = 0;
    int value = 1;

    for (int i = 0; i < str.length(); i++) {
      char ch = str.charAt(i);
      // (, [ 일 경우 스택에 넣고 값
      if (ch == '(') {
        stack.push(ch);
        value *= 2;
      }
      else if (ch == '[') {
        stack.push(ch);
        value *= 3;
      }

      // ) 일 경우
      else if (ch == ')') {
        // 1-0. 스택이 비어있다면 (처음부터 )나온 경우) or 앞에 매칭된게 (가 아닌 경우
        if (stack.empty() || stack.peek() != '(') {
          System.out.println(0);
          return;
        }
        // 1-1. 바로 앞 index가 (라면 쌍 생겼으니까 더하면 됨
        else if (str.charAt(i-1) == '(') result += value;
        // 1-2. 바로 앞 index는 아닌데 스택 Peek이 ( 인 경우 -> '([]())' 같이 겹쳐있는 케이스
        // 위 else if에서 안에 겹쳐있는 값들 result 더해줄 때, 밖의 괄호 값이 곱해져 있는 상태에서 더한것! 나눠줘야 함
        value /= 2;
        // 매칭쌍 (stack.peek) 삭제
        stack.pop();
      }

      // 1과 동일
      else if (ch == ']') {
        if (stack.empty() || stack.peek() != '[') {
          System.out.println(0);
          return;
        }
        else if (str.charAt(i-1) == '[') result += value;
        value /= 3;
        stack.pop();
      }
      }

    // ()()( 같은 경우, stack에 값이 남아있음 -> 이 케이스도 0으로 출력 필요
    if (!stack.empty()) {
      System.out.println(0);
    } else {
      System.out.println(result);
    }
    }

  }

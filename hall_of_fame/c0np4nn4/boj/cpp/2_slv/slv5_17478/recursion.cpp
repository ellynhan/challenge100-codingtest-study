#include <iostream>

using namespace std;

const char * first_line = R"(어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.)";

const char * recursive_line_1 = R"("재귀함수가 뭔가요?")";
const char * recursive_line_2 = R"("잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.)";
const char * recursive_line_3 = R"(마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.)";
const char * recursive_line_4 = R"(그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.")";

const char * answer_line_1 = R"("재귀함수는 자기 자신을 호출하는 함수라네")";
const char * answer_line_2 = R"(라고 답변하였지.)";

int n;

void print_indent(int times) {
  for (int i = 0; i < times * 4; i++) {
    cout << '_';
  }
}

void print_lines(int time) {
  if (time == n) {
    print_indent(time);
    cout << recursive_line_1 << '\n';

    print_indent(time);
    cout << answer_line_1 << '\n';

    print_indent(time);
    cout << answer_line_2 << '\n';

    return;
  }

  print_indent(time);
  cout << recursive_line_1 << '\n';

  print_indent(time);
  cout << recursive_line_2 << '\n';

  print_indent(time);
  cout << recursive_line_3 << '\n';

  print_indent(time);
  cout << recursive_line_4 << '\n';

  print_lines(time + 1);

  print_indent(time);
  cout << answer_line_2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  cout << first_line << '\n';
  print_lines(0);
  
  return 0;
}

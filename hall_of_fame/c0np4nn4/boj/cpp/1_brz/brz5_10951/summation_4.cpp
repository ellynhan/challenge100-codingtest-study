#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string line;
  while (true) {
    getline(cin, line);

    if (line.size() != 3) {
      break;
    }

    char a = line[0] - '0';

    char b = line[2] - '0';

    cout << a + b << '\n';

  }

  return 0;
}

#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string msg;
  getline(cin, msg);

  stringstream ss(msg);
  string temp;

  int cnt = 0;
  while (getline(ss, temp, ' ')) {
    if (temp == "") continue;
    cnt++;
  }

  cout << cnt << '\n';

  return 0;
}

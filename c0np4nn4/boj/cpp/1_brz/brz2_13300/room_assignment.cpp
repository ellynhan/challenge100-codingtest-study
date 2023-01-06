#include <iostream>

using namespace std;

int students[2][7];
int count = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  while(n--) {
    int s, y;
    cin >> s >> y;

    students[s][y] += 1;

    if (students[s][y] > 0 && students[s][y] % k == 0) {
      students[s][y] = 0;
      count++;
    }
  }

  for(int i = 1; i < 7; i++) {
    if (students[0][i] > 0) count++;
    if (students[1][i] > 0) count++;
  }

  cout << count << '\n';

  return 0;
}

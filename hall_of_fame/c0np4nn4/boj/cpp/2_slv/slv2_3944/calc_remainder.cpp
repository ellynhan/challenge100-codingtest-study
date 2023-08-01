#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 0;
  cin >> t;

  while (t > 0) {
    int p = 0;
    cin >> p;

    if (p < 2 || p > 10) {
      exit(1);
    }

    string value;
    cin >> value;

    int sum = 0;
    for (int i = 0; i < value.length(); i++) {
      if (value[i] - '0' == (p - 1))
        continue;

      sum += ((value[i] - '0') % (p - 1));
    }

    cout << sum % (p - 1) << endl;

    t--;
  }

  return 0;
}

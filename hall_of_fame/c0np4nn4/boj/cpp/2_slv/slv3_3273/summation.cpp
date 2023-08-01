#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;
int cnt = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;

    seq.push_back(num);
  }

  sort(seq.begin(), seq.end());

  int target;
  cin >> target;

  for (vector<int>::iterator iter = seq.begin(); iter != seq.end(); iter++) {
    if (target > *iter) {
      auto it = find(seq.begin(), seq.end(), (target - *iter));

      if (it != seq.end()) {
        cnt += 1;
      }
    }
  }

  cout << cnt / 2 << '\n';

  return 0;
}

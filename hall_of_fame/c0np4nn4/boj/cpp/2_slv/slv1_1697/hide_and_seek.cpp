#include <iostream>
#include <queue>

using namespace std;

queue<int> pos;

int walk[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fill(walk, walk + 100001, 9999999);

  int n, k;
  cin >> n >> k;

  pos.push(n);
  walk[n] = 0;

  while (!pos.empty()) {
    int cur = pos.front(); pos.pop();

    // cout << "\n[+] cur: " << cur << endl;
    // cout << "[+] walk: " << walk[cur] << endl;

    if (cur == k) {
      cout << walk[cur] << '\n';
      break;
    }
    
    if (cur + 1 <= 200000 && walk[cur + 1] > walk[cur] + 1)  {
      // cout << "[_] cur + 1: " << cur + 1 << endl;
      walk[cur + 1] = walk[cur] + 1;
      pos.push(cur + 1);
    }

    if (cur - 1 >= 0 && walk[cur - 1] > walk[cur] + 1) {
      // cout << "[_] cur - 1: " << cur - 1 << endl;
      walk[cur - 1] = walk[cur] + 1;
      pos.push(cur - 1);
    }

    if (cur * 2 <= 200000 && walk[cur * 2] > walk[cur] + 1) {
      // cout << "[_] cur * 2: " << cur * 2 << endl;
      walk[cur * 2] = walk[cur] + 1;
      pos.push(cur * 2);
    }
  }

  return 0;
}

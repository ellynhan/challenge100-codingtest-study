#include <iostream>
#include <queue>

using namespace std;

// int computer[101];
queue<int> computer[101];
queue<int> Q;

bool vis[101];

int ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }

  int t;
  cin >> t;

  while (t--) {
    int from, to;
    cin >> from >> to;

    computer[from].push(to);
    computer[to].push(from);
  }

  vis[1] = true;
  Q.push(1);

  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();

    while (!computer[cur].empty()) {
      int nxt = computer[cur].front(); computer[cur].pop();

      if (vis[nxt] == true) continue;

      ans++;
      vis[nxt] = true;
      Q.push(nxt);
    }
  }

  cout << ans << '\n';

  return 0;
}

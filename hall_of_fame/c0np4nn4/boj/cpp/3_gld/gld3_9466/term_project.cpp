#include <algorithm>
#include <iostream>

#define DEFAULT 0
#define IN_LOOP 111111

using namespace std;

int t, n, ans, cnt;
int link[100001];
int state[100001];

void check(int x) {
  int cur = x;

  while (true) {
    state[cur] = x;
    cur = link[cur];  // next point

    if (state[cur] == x) {
      while (state[cur] != IN_LOOP) {
        state[cur] = IN_LOOP;
        cur = link[cur];
      }
      return;
    } else if (state[cur] != DEFAULT) {
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;

    fill(state + 1, state + n + 1, DEFAULT);

    for (int i = 1; i <= n; i++) {
      cin >> link[i];
    }

    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (state[i] == DEFAULT) check(i);
    }

    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (state[i] != IN_LOOP) {
        // cout << "find, i: " << i << endl;
        cnt++;
      }
    }

    cout << cnt << '\n';
  }


  return 0;
}

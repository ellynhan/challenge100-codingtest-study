#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
queue<pair<int, int> > q;
int prio[10] = {0};

void input()
{
  FOR(i, 10) prio[i] = 0;

  cin >> N >> M;
  FOR(n, N) {
    int priority;
    cin >> priority;
    prio[priority]++;
    q.push({priority, n});
  }
}

void solve()
{
  int i = 1;
  while(!q.empty()) {
    int priority = q.front().first;
    int index = q.front().second;
    q.pop();
    bool goBack = false;
    for (int p = priority + 1; p < 10; p++) {
      if (prio[p]) {
    // cout << index << ' ';
        q.push({priority, index});
        goBack = true;
        break;
      }
    }
    if (goBack) continue;

    if (index == M) cout << i << '\n';
    prio[priority]--;
    i++;
  }
}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  int T;
  cin >> T;
  FOR(t, T) {
    input();
    solve();
  }
}
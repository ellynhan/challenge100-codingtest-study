#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 100
#define INF 1987654321

int N, K;
int coin[MAX] = {0};
int DP[10001] = {0};

void input()
{
  cin >> N >> K;
  FOR(n, N) {
    cin >> coin[n];
  }
  sort(&coin[0], &coin[N]);
}

void solve()
{
  DP[0] = 0;
  FOR(k, K + 1) {
    int tmp = INF;
    FOR(n, N) {
      if (k - coin[n] == 0) {
        tmp = min(tmp, DP[k - coin[n]] + 1);
      } else if (k - coin[n] > 0) {
        if (DP[k - coin[n]] > 0) {
          tmp = min(tmp, DP[k - coin[n]] + 1);
        }
      }
    }
    DP[k] = tmp == INF ? 0 : tmp;
  }
}

void print()
{
  // cout << '\n';
  // FOR(k, K) {
  //   cout << DP[k] << ' ';
  // }
  if (DP[K] == 0) cout << -1 << '\n';
  else            cout << DP[K] << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}
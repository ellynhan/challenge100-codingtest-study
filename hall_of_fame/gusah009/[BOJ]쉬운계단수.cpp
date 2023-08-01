#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 100
#define MOD 1000000000

int N;
int DP[MAX][10] = {0};
int answer = 0;

void input()
{
  cin >> N;
}

int DFS(int i, int depth)
{
  if (depth == N) {
    return 1;
  }

  if (DP[depth][i] != 0) return DP[depth][i];

  int ret = 0;
  if (i != 9) {
    ret += DFS(i + 1, depth + 1) % MOD;
  }
  if (i != 0) {
    ret += DFS(i - 1, depth + 1) % MOD;
  }
  DP[depth][i] = ret % MOD;
  return DP[depth][i];
}

void solve()
{
  for (int i = 1; i < 10; i++) {
    answer += DFS(i, 1) % MOD;
    answer %= MOD;
  }
}

void print()
{
  cout << answer << '\n';
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
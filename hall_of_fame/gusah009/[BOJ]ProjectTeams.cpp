#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N;
int W[10000] = {0};
int answer = INF;

void input()
{
  cin >> N;
  FOR(n, 2 * N) {
    cin >> W[n];
  }
  sort(&W[0], &W[2 * N]);
}

void solve()
{
  FOR(n, N) {
    answer = min(answer, W[n] + W[2 * N - 1 - n]);
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
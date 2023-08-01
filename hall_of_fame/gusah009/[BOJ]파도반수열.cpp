#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 101

int N;
unsigned long long DP[MAX] = {0};

void input()
{
  cin >> N;
}

void solve()
{
  DP[0] = 1;
  DP[1] = 1;
  DP[2] = 1;
  DP[3] = 2;
  DP[4] = 2;
  for(int n = 5; n <= MAX; n++) {
    DP[n] = DP[n - 1] + DP[n - 5];
  }
}

void print()
{
  cout << DP[N - 1] << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  int T;
  cin >> T;
  FOR(t, T) {
    input();
    print();
  }
}
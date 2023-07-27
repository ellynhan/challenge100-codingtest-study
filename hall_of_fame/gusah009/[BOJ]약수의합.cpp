#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 1; i <= j; i++)

int N;
int answer = 0;

void input()
{
  cin >> N;
}

void solve()
{
  FOR(n, N) {
    if (N % n == 0) answer += n;
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
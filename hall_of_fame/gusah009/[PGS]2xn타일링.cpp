#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 1000000007

unsigned int DP[60001] = {0};
int N;

void input()
{
  cin >> N;
  DP[0] = 0;
  DP[1] = 1;
  DP[2] = 2;
}

void solve()
{
  for (int i = 3; i <= N; i++) {
    DP[i] = DP[i - 2] + DP[i - 1];
    DP[i] %= MAX;
  }
}

void print()
{
  cout << DP[N] << '\n';
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
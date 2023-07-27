#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 2; i < j; i++)
#define MAX 1000001

int N;
int DP[MAX] = {0};

void input()
{ 
  cin >> N;
}

void solve()
{
  DP[0] = 0;
  DP[1] = 1;
  DP[2] = 2;
  FOR(i, N) {
    DP[i + 1] = DP[i] + DP[i - 1];
    DP[i + 1] %= 15746;
  }
}

void print()
{
  cout << DP[N];
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
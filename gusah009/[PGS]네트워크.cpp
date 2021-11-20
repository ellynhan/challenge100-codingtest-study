#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
int edge[201][201] = {0};
int answer = 0;
int isNetworking[201] = {0};

void input()
{
  cin >> N;
  int tmp;
  FOR(i, N) {
    FOR(j, N) {
      cin >> tmp;
      edge[i][j] = tmp;
    }
  }
}

void DFS(int node)
{
  // cout << node << '\n';
  if (isNetworking[node]) return;
  isNetworking[node] = true;

  FOR(n, N) {
    if (edge[node][n]) {
      DFS(n);
    }
  }
}

void solve()
{
  FOR(n, N) {
    if (!isNetworking[n]) {
      // cout << n << "!!!\n";
      DFS(n);
      answer++;
    }
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
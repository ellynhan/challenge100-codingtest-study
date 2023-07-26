#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 7

int N, M;
int arr[MAX];

void input()
{
  cin >> N >> M;
}

void DFS(int index)
{
  if (index == M) {
    FOR(m, M) {
      cout << arr[m] << ' ';
    }
    cout << '\n';
    return;
  }

  FOR(n, N) {
    arr[index] = n + 1;
    DFS(index + 1);
  }
  return;
}

void solve()
{
  DFS(0);
}

void print()
{

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
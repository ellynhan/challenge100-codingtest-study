#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
double P[4];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
double answer = 0;

bool board[29][29] = {0};

void input()
{
  cin >> N;
  FOR(i, 4) {
    cin >> P[i];
    P[i] /= 100;
  }
}

void DFS(pair<int, int> point, int n, double probability)
{
  int x = point.first;
  int y = point.second;

  if (board[x][y] == true) return;

  if (n == N) {
    answer += probability;
    return;
  }

  board[x][y] = true;
  FOR(i, 4) {
    DFS({x + dir[i][0], y + dir[i][1]}, n + 1, probability * P[i]);
  }
  board[x][y] = false;
  return;
}

void solve()
{
  FOR(i, 29) {
    FOR(j, 29) {
      board[i][j] = false;
    }
  }
  pair<int, int> start = {14, 14};

  DFS(start, 0, 1);
}

void print()
{
  cout << fixed;
  cout.precision(9);
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
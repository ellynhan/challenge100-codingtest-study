#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N, M, K;
bool board[100][100] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int answer = 0;

void input()
{
  cin >> N >> M >> K;
  int y, x;
  FOR(k, K)
  {
    cin >> y >> x;
    board[y - 1][x - 1] = true;
  }
}

int DFS(int y, int x)
{
  board[y][x] = 0;
  
  int cnt = 1;

  FOR(d, 4)
  {
    int next_y = y + dir[d][0];
    int next_x = x + dir[d][1];

    if ((0 <= next_y && next_y < N) &&
        (0 <= next_x && next_x < M) &&
        board[next_y][next_x]) {
          cnt += DFS(next_y, next_x);
        }
  }

  return cnt;
}

void solve()
{
  FOR(i, 100)
  {
    FOR(j, 100)
    {
      if (board[i][j])
      {
        answer = max(answer, DFS(i, j));
      }
    }
  }
}

void print()
{
  cout << answer << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}
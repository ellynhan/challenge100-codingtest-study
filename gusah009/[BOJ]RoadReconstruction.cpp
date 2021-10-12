#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int M, N;
int board[1001][1001] = {0};
int DP[1001][1001] = {0};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int answer = -1;

void input()
{
  cin >> M >> N;
  FOR(m, M) {
    FOR(n, N) {
      cin >> board[m][n];
    }
  }
  FOR(m, M) {
    FOR(n, N) {
      DP[m][n] = -INF;
    }
  }
}

void solve()
{
  priority_queue<pair<int, pair<int, int> > > PQ;
  if (board[0][0] != -1) PQ.push({-board[0][0], {0, 0}});
  DP[0][0] = -board[0][0];

  int cost, x, y, nextX, nextY;
  while(!PQ.empty()) {
    cost = PQ.top().first;
    x = PQ.top().second.first;
    y = PQ.top().second.second;
    PQ.pop();

    if (x == M - 1 && y == N - 1) {
      answer = -cost;
      return;
    }
    // cout << x << ' ' << y << '\n';
    DP[x][y] = cost;

    FOR(i, 4) {
      nextX = x + dir[i][0];
      nextY = y + dir[i][1];
      if (0 <= nextX && nextX < M &&
          0 <= nextY && nextY < N &&
          board[nextX][nextY] != -1 &&
          DP[nextX][nextY] < cost - board[nextX][nextY]) {
            PQ.push({cost - board[nextX][nextY], {nextX, nextY}});
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
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}
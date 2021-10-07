#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int board[100][100] = {0};
int meltTime = 0;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    FOR(m, M) {
      cin >> board[n][m];
    }
  }
}

void findOutAir(int n, int m) {
  board[n][m] = -2;
  FOR(i, 4) {
    int next_n = n + dir[i][0];
    int next_m = m + dir[i][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        board[next_n][next_m] == 0) {
          findOutAir(next_n, next_m);
        }
  }
}

void isMelting(int n, int m) {
  int nearByZero = 0;
  FOR(i, 4) {
    int next_n = n + dir[i][0];
    int next_m = m + dir[i][1];
    if (board[next_n][next_m] == -2) nearByZero++;
  }
  if (nearByZero >= 2) board[n][m] = -1;
}

void solve()
{
  bool allMeltFlag = false;
  while (!allMeltFlag) {
    allMeltFlag = true;
    FOR(n, N) {
      FOR(m, M) {
        if (board[n][m] == -2) {
          board[n][m] = 0;
        }
      }
    }
    findOutAir(0, 0);
    // cout << "?";
    FOR(n, N) {
      FOR(m, M) {
        if (board[n][m] == 1) {
          allMeltFlag = false;
          isMelting(n, m);
        }
      }
    }
    FOR(n, N) {
      FOR(m, M) {
        if (board[n][m] == -1) {
          board[n][m] = 0;
        }
      }
    }
    meltTime++;
  }
}

void print()
{
  cout << meltTime - 1 << '\n';
}

int main()
{
  // ios_base :: sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  input();
  solve();
  print();
}
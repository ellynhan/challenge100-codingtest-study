#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 1001

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int N, M;
int sameAreaNum = 1;
int board[MAX][MAX] = {0};
int answerBoard[MAX][MAX] = {0};
int sameArea[MAX][MAX] = {0};

void input()
{
  fill(&board[0][0], &board[MAX - 1][MAX], -1);

  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    FOR(m, M) {
      board[n][m] = tmp[m] == '0' ? 0 : -1;
      answerBoard[n][m] = tmp[m] == '0' ? 0 : -1;
      sameArea[n][m] = tmp[m] == '0' ? 0 : -1;
    }
  }
}

int dfsFind(int n, int m)
{
  board[n][m] = -2;
  int blank = 1;
  FOR(d, 4) {
    int next_n = n + dir[d][0];
    int next_m = m + dir[d][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        board[next_n][next_m] == 0) {
          blank += dfsFind(next_n, next_m);
        }
  }
  return blank;
}

void dfsFill(int n, int m, int fillNum)
{
  board[n][m] = fillNum;
  sameArea[n][m] = sameAreaNum;
  FOR(d, 4) {
    int next_n = n + dir[d][0];
    int next_m = m + dir[d][1];
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        board[next_n][next_m] == -2) {
          dfsFill(next_n, next_m, fillNum);
        }
  }
}

void fillAnswer(int n, int m)
{
  int result = 1;
  vector<int> isSameArea;
  FOR(d, 4) {
    bool flag = true;
    int next_n = n + dir[d][0];
    int next_m = m + dir[d][1];
    FOR(i, isSameArea.size()) {
      if (isSameArea[i] == sameArea[next_n][next_m]) {
        flag = false;
      }
    }
    if (0 <= next_n && next_n < N &&
        0 <= next_m && next_m < M &&
        flag &&
        board[next_n][next_m] != -1) {
          result += board[next_n][next_m];
          isSameArea.push_back(sameArea[next_n][next_m]);
        }
  }
  answerBoard[n][m] = result;
}

void solve()
{
  FOR(n, N) {
    FOR(m, M) {
      if (board[n][m] == 0) {
        int blanks = dfsFind(n, m);
        dfsFill(n, m, blanks);
        sameAreaNum++;
      }
    }
  }

  FOR(n, N) {
    FOR(m, M) {
      if (board[n][m] == -1) {
        fillAnswer(n, m);
      }
    }
  }
}

void print()
{
  //   cout << '\n';
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << board[n][m];
  //   }
  //   cout << '\n';
  // }
  //   cout << '\n';
  // FOR(n, N) {
  //   FOR(m, M) {
  //     cout << sameArea[n][m];
  //   }
  //   cout << '\n';
  // }
  //   cout << '\n';
  FOR(n, N) {
    FOR(m, M) {
      cout << answerBoard[n][m] % 10;
    }
    cout << '\n';
  }
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
#include <iostream>
#include <string>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 50

int N, M;
int maxSize = MAX;
int board[MAX][MAX] = {0};
int answer = 1;

void input()
{
  cin >> N >> M;
  FOR(n, N) {
    string tmp;
    cin >> tmp;
    FOR(m, M) {
      board[n][m] = tmp[m] - '0';
    }
  }

  maxSize = min(N, M);
}

void solve()
{
  for (int size = 1; size < maxSize; size++) {
    for (int i = 0; i < N - size; i++) {
      for (int j = 0; j < M - size; j++) {
        if (board[i][j] == board[i][j + size] &&
            board[i][j] == board[i + size][j] &&
            board[i][j] == board[i + size][j + size])
              answer = max(answer, (size + 1) * (size + 1));
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
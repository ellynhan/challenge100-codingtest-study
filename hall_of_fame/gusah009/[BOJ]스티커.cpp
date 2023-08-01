#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int answer = -1;
int sticker[2][100001];
int DP[2][100001][2] = {0}; // 선택 했을 때, 안했을 때
int T;
int N;

void input()
{
  FOR(i, 2) {
    FOR(j, 100001) {
      FOR(k, 2) {
        DP[i][j][k] = 0;
      }
    }
  }

  cin >> N;
  FOR(i, 2) {
    FOR(n, N) {
      cin >> sticker[i][n];
    }
  }
}

void solve()
{
  DP[0][0][0] = sticker[0][0];
  DP[1][0][0] = sticker[1][0];
  FOR(n, N - 1) {
    FOR(i, 2) {
      DP[i][n + 1][0] = max(max(DP[(i + 1) % 2][n][0], DP[(i + 1) % 2][n][1]), DP[i][n][1]) + sticker[i][n + 1];
      DP[i][n + 1][1] = DP[i][n][0];
    }
  }
  
  answer = -1;
  FOR(i, 2) {
    FOR(n, N) {
      answer = max(answer, DP[i][n][0]);
    }
  }
  FOR(i, 2) {
    FOR(n, N) {
      answer = max(answer, DP[i][n][1]);
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
  cin >> T;
  FOR(t, T) {
    input();
    solve();
    print();
  }
}
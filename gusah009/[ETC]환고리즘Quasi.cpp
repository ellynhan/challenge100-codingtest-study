#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 110 + 1
#define f first
#define s second

string S, T;
pair<string, int> dp[MAX][MAX];
string answer = "";

void init()
{
  FOR(i, MAX) {
    FOR(j, MAX) {
      dp[i][j].f = "";
      dp[i][j].s = 0;
    }
  }
}

void input()
{
  cin >> S >> T;
  
  init();
}

void solve()
{
  for(int s = 1; s <= S.size(); s++) {
    for (int t = 1; t <= T.size(); t++) {
      dp[s][t] = dp[s - 1][t];
      dp[s][t].s -= 1;
      if (S[s - 1] == T[t - 1]) {
        if (t == 1) dp[s][t].f = T[t - 1];
        else {
          if (dp[s - 1][t - 1].f.size() > dp[s - 1][t - 2].f.size()) {
            dp[s][t].f = dp[s - 1][t - 1].f + T[t - 1];
          } else if (dp[s - 1][t - 1].f.size() < dp[s - 1][t - 2].f.size()) {
            dp[s][t].f = dp[s - 1][t - 2].f + T[t - 1];
          } else {
            dp[s][t].f = min(dp[s - 1][t - 1].f, dp[s - 1][t - 2].f) + T[t - 1];
          }
        }
        
        if (dp[s - 1][t].f.size() > dp[s][t].f.size()) {
          dp[s][t] = dp[s - 1][t];
          dp[s][t].s -= 1;
        } else {
          dp[s][t].s = 2;
        }
      } else {
        dp[s][t].f = dp[s][t].s <= 0 ? "" : dp[s][t].f;
      }

      if (answer.size() < dp[s][t].f.size()) answer = dp[s][t].f;
      else if (answer.size() == dp[s][t].f.size()) answer = min(answer, dp[s][t].f);
    }
  }
}

void print()
{
  // FOR(i, S.size()) {
  //   FOR(j, T.size()) {
  //     cout << dp[i+1][j+1].s << ':' << dp[i+1][j+1].f << '\t';
  //   }
  //   cout << '\n';
  // }

  cout << answer << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  swap(S, T);
  solve();
  print();
}
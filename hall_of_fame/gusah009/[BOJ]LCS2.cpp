#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX 1001

string A, B;
int DP[MAX][MAX] = {0};
stack<char> answer;

void input()
{
  cin >> B;
  cin >> A;
}

void solve()
{
  FOR(a, A.size()) {
    FOR(b, B.size()) {
      if (A[a] == B[b]) {
        DP[a + 1][b + 1] = max(DP[a + 1][b + 1] , DP[a][b]+ 1);
      }
      else {
        DP[a + 1][b + 1] = max(DP[a][b + 1], DP[a + 1][b]);
      }
    }
  }

  // FOR(a, A.size() + 1) {
  //   FOR(b, B.size() + 1) {
  //     cout << DP[a][b] <<' ';
  //   }
  //   cout << '\n';
  // }
  int a = A.size();
  int b = B.size();
  while(a != 0 && b != 0) {
    while(b != 0 && DP[a][b] == DP[a][b - 1]) b--;
    while(a != 0 && DP[a][b] == DP[a - 1][b]) a--;
    if (DP[a][b] == 0) break;
    answer.push(A[a - 1]);
    a--;
    b--;
  }
}

void print()
{
  cout << answer.size() << '\n';
  while (!answer.empty()) {
    cout << answer.top();
    answer.pop();
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
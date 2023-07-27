#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define START 1

int N, M;
int cursor = START;
bool Q[50] = {0};
int answer = 0;

void input_solve()
{
  cin >> N >> M;
  FOR(m, M) {
    int tmp;
    cin >> tmp;

    int res1 = 0, res2 = 0;
    
    if (cursor < tmp) {
      for (int i = cursor; i > 0; i--) {
        if (Q[i] == 0) res1++;
      }
      for (int i = N; i > tmp; i--) {
        if (Q[i] == 0) res1++;
      }

      for (int i = cursor; i < tmp; i++) {
        if (Q[i] == 0) res2++;
      }
    } else {
      for (int i = cursor; i > tmp; i--) {
        if (Q[i] == 0) res1++;
      }

      for (int i = cursor; i <= N; i++) {
        if (Q[i] == 0) res2++;
      }
      for (int i = 1; i < tmp; i++) {
        if (Q[i] == 0) res2++;
      }
    }

    // cout << "res1, res2: " << res1 << ' ' << res2 << '\n';
    answer += min(res1, res2);
    Q[tmp] = 1;

    if (m == N - 1) break;

    while (Q[tmp % N + 1] == 1) tmp++;
    cursor = tmp % N + 1;
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
  input_solve();
  print();
}
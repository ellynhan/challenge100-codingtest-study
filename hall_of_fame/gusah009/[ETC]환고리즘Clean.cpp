#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define N_MAX 100
#define MOVE_COST 10
#define DATES 365 * 3 + 1
#define f first
#define s second

int N;
// {{end, require_time}, cost}
pair<pair<int ,int>, int> info[N_MAX];
// cost, dates
pair<int, int> DP[DATES];

void input()
{
  int b, e, c;
  cin >> N;
  FOR(n, N) {
    cin >> b >> e >> c;
    info[n] = {{e, e - b + 1}, c};
  }
}

void solve()
{
  sort(&info[0], &info[N]);
  DP[0] = {0, 0};
  int taskIndex = 0;
  for (int date = 1; date < DATES; date++) {
    DP[date] = DP[date - 1];
    while(taskIndex < N && info[taskIndex].f.f == date) {
      int cost = DP[date - info[taskIndex].f.s].f + info[taskIndex].s - MOVE_COST;
      int dates = DP[date - info[taskIndex].f.s].s + info[taskIndex].f.s;
      if (cost > DP[date].f || cost == DP[date].f && dates < DP[date].s) DP[date] = {cost, dates};
      taskIndex++;
    }
  }
}

void print()
{
  cout << DP[DATES - 1].f + 10 << ' ' << DP[DATES - 1].s << '\n';
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
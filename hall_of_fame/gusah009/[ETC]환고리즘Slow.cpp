#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define MAX_TASK 100
#define MAX_DAY 10
#define MAX_MACHINE 5

int N, T, k, c, d;
pair<int, int> tasks[MAX_TASK];
vector<int> maximumTask[MAX_DAY];
int maxAnswer, secondMaxAnswer;

void input()
{
  cin >> N >> T >> k;
  FOR(n, N) {
    cin >> c >> d;
    tasks[n].first = -c;
    tasks[n].second = d - 1;
  }
}


void solve()
{
  sort(&tasks[0], &tasks[N]);
  int curProfit, curDueDate;
  FOR(n, N) {
    curProfit = tasks[n].first;
    curDueDate = tasks[n].second;
    while (curDueDate >= 0) {
      if (maximumTask[curDueDate].size() == k) {
        curDueDate--;
        continue;
      }
      maximumTask[curDueDate].push_back(curProfit);
      tasks[n].second = -1;
      break;
    }
  }

  FOR(t, T) {
    FOR(i, maximumTask[t].size()) {
      maxAnswer += maximumTask[t][i];
    }
  }

  for (int n = N - 1; n >= 0; n--) {
    if (tasks[n].second == -1) {
      secondMaxAnswer = maxAnswer - tasks[n].first;
      break;
    }
  }

  FOR(n, N) {
    curProfit = tasks[n].first;
    curDueDate = tasks[n].second;
    if (curDueDate == -1) continue;
    FOR(i, curDueDate + 1) {
      FOR(j, maximumTask[i].size()) {
        int result = maxAnswer - (maximumTask[i][j] - curProfit);
        if (result == maxAnswer) continue;
        secondMaxAnswer = min(secondMaxAnswer, result);
      }
    }
    
  }
}

void print()
{
  cout << -maxAnswer << ' ' << -secondMaxAnswer << '\n';
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
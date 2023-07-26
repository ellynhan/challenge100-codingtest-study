#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

long long N, M, K;
long long arr[1000001] = {0};
long long sumArr[1000001] = {0};
vector<pair<long long, long long> > turnInto;

void input_solve_print()
{
  cin >> N >> M >> K;
  FOR(n, N) cin >> arr[n + 1];
  sumArr[0] = 0;
  FOR(n, N) sumArr[n + 1] = sumArr[n] + arr[n + 1];
  long long flag, index, chg, start, end;
  FOR(m, M + K) {
    cin >> flag;
    if (flag == 1) {
      cin >> index >> chg;
      long long now_index;
      bool pushFlag = true;
      FOR(i, turnInto.size()) {
        now_index = turnInto[i].first;
        if (index == now_index) {
          turnInto[i].second = chg - arr[index];
          pushFlag = false;
          break;
        }
      }
      if (pushFlag) turnInto.push_back({index, chg - arr[index]});
    }
    else if (flag == 2) {
      cin >> start >> end;
      long long ans = sumArr[end] - sumArr[start - 1];
      long long now_index, now_chg;
      FOR(i, turnInto.size()) {
        now_index = turnInto[i].first;
        now_chg = turnInto[i].second;
        if (start <= now_index && now_index <= end) {
          ans += now_chg;
        }
      }
      cout << ans << '\n';
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input_solve_print();
}
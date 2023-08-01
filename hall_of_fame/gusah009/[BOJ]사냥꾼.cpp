#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M, L;
int answer = 0;

set<int> shootPlace;
vector<pair<int, int> > animals;

void input()
{
  cin >> M >> N >> L;
  FOR(m, M) {
    int x;
    cin >> x;
    shootPlace.insert(x);
  }
  FOR(n, N) {
    int x, y;
    cin >> x >> y;
    animals.push_back({x, y});
  }
  sort(animals.begin(), animals.end());
}

void solve()
{
  FOR(n, N) {
    auto nearPlace1 = shootPlace.lower_bound(animals[n].first);
    if (nearPlace1 != shootPlace.end()) {
      if (abs(animals[n].first - *nearPlace1) + animals[n].second <= L) {
        answer++;
        continue;
      }
    }
    if (nearPlace1 != shootPlace.begin()) {
      auto nearPlace2 = prev(nearPlace1);
      if (abs(animals[n].first - *nearPlace2) + animals[n].second <= L) {
        answer++;
        continue;
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
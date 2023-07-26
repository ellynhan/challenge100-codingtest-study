#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

queue<ll> names[21];
ll ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    string name;
    cin >> name;

    int name_idx = name.size();

    while (!names[name_idx].empty() && names[name_idx].front() + k < i) {
        names[name_idx].pop();
    }

    ans += (ll) names[name_idx].size();

    names[name_idx].push(i);
  }

  cout << ans << '\n';

  return 0;
}

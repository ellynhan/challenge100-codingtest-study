#include <iostream>
#include <stack>

using namespace std;
using ll=long long;

stack<pair<ll, ll>> st;
ll ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    ans = 0;

    int n;
    cin >> n;

    if (n==0) break;

    for (ll i = 0; i < n; i++) {
      ll h;
      cin >> h;

      ll idx = i;
      while (!st.empty() && st.top().second >= h) {
        ll area = (i - st.top().first) * st.top().second;

        if (area > ans) ans = area;

        idx = st.top().first;

        st.pop();
      }

      st.push(make_pair(idx, h));

    }
    while (!st.empty()) {
      ll area = (n - st.top().first) * st.top().second; 

      if (area > ans) ans = area;

      st.pop();
    }

    cout << ans << endl;
  }
  return 0;
}

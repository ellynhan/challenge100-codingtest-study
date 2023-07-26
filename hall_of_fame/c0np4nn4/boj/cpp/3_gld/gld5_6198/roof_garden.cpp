#include <iostream>
#include <stack>

using namespace std;
using ll=long long;

stack<pair<ll, ll>> st;
stack<ll> rev;

ll sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll height;
    cin >> height;

    rev.push(height);

  }

  for(ll i = 0; i < n && !rev.empty(); i++) {
    ll height = rev.top();
    rev.pop();

    if (st.empty()) {
      // cout << "[+1] h: " << height << ", add: "  << i << endl;

      // sum += 0;

      st.push(make_pair(i, height));
    } else {
      while (!st.empty() && st.top().second < height) {
        st.pop();
      }

      if (st.empty()) {
        // cout << "[+2] h: " << height << ", add: "  << i << endl;

        sum += i;

        st.push(make_pair(i, height));
      } else {
        // cout << "[+3] h: " << height << ", add: "  << i - st.top().first - 1<< endl;

        sum += (i - st.top().first - 1);

        st.push(make_pair(i, height));
      }
    }

  }
  cout << sum << '\n';

  return 0;
}

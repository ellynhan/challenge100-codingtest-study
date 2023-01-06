#include <iostream>
#include <deque>

using namespace std;
using ll=long long;

deque<pair<ll,ll>> buffer;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, l;
  cin >> n >> l;

  pair<ll, ll> min = make_pair(-1, -1);
  for (ll i = 1; i <= n; i++) {
    ll v;
    cin >> v;

    // minimum value always at the front
    if (buffer.empty()) {
      buffer.push_back(make_pair(i, v));
    } else {
      if (v > buffer.back().second) {
        buffer.push_back(make_pair(i, v));
      } else {
        while (!buffer.empty() && buffer.back().second >= v) {
          buffer.pop_back();
        }
        buffer.push_back(make_pair(i, v));
      }
      while (!buffer.empty() && buffer.front().first < (i - l + 1)) {
        buffer.pop_front();
      }
    }

    // cout << "\n[+] buffer check" << endl;
    // auto tmp = buffer;
    // while (!tmp.empty()) {
    //   cout << '(' << tmp.front().first << ", " << tmp.front().second << ')' << endl;
    //   tmp.pop_front();
    // }
    // cout << endl;
    cout << buffer.front().second << ' ';
  }
  cout << '\n';


  return 0;
}

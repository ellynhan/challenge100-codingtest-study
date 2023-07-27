#include <iostream>
#include <stack>

using namespace std;

using ll = long long;

stack<pair<ll,ll>> ppl;

ll ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    ll height;
    cin >> height;

    ll height_cnt = 1;

    // cout << endl;

    while (!ppl.empty() && ppl.top().first <= height) {
      // cout << "[+] ans += " << ppl.top().second << endl;
      ans += ppl.top().second;

      if (ppl.top().first == height) {
        height_cnt = ppl.top().second + 1;
      }

      ppl.pop();
      // cout << "[+] pop" << endl;
    }

    if (!ppl.empty()) {
      ans += 1;
      // cout << "[+] ans++" << endl;
    }

    // cout << "[+] push: (" << height << ", " << height_cnt << ")" << endl;
    ppl.push(make_pair(height, height_cnt));

    // cout << "[+] (stack top): (" << ppl.top().first << ", " << ppl.top().second << ")" << endl;
    // cout << "[+] (stack size): " << ppl.size() << endl;
  }


  cout << ans << '\n';
  return 0;
}


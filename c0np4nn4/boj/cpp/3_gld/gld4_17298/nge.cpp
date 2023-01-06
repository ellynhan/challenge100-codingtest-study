#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<pair<int, int>> st;
vector<int> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  ans.resize(n);
  fill(ans.begin(), ans.end(), -1);

  for(int i = 0; i < n; i++) {
    int value;
    cin >> value;

    while (!st.empty() && st.top().second < value) {
      ans[st.top().first] = value;
      st.pop();
    }

    st.push(make_pair(i, value));
  }


  for (auto n: ans) {
    cout << n << ' ';
  }
  cout << endl;
}

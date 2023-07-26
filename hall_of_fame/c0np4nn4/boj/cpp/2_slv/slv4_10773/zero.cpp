#include <iostream>
#include <stack>

using namespace std;

stack<long long> st;

long long sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;

  while(k--) {
    long long num;
    cin >> num;

    if (num != 0) {
      st.push(num);
    } else {
      st.pop();
    }
  }

  while(!st.empty()) {
    sum += st.top();
    st.pop();
  }

  cout << sum << '\n';

  return 0;
}

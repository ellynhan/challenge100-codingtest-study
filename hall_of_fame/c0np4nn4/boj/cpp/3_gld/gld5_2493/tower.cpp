#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<pair<int, int>> towers;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    int tower_height;
    cin >> tower_height;

    if (towers.empty()) {
      cout << 0 << ' ';
      towers.push(make_pair(i, tower_height));
    } else {
      while (!towers.empty() && towers.top().second < tower_height) {
        towers.pop();
      }
      if (towers.empty()) {
        cout << 0 << ' ';
        towers.push(make_pair(i, tower_height));
      } else {
        cout << towers.top().first << ' ';
        towers.push(make_pair(i, tower_height));
      }
    }

  }
  cout << '\n';


  return 0;
}

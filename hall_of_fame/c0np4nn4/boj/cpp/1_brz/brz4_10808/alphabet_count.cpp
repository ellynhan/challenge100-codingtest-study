#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int count[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;

  vector<char> s_vec(s.begin(), s.end());

  for(char c: s_vec) {
    count[(int)(c - 'a')] += 1;
  }

  for(int cnt: count) {
    cout << cnt << ' ';
  }
  cout << '\n';
  
  return 0;
}

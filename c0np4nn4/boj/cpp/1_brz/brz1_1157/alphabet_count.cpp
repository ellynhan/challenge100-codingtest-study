#include <iostream>

using namespace std;

int count[26];
int max_n;
char ans;

int main() {
  string word;
  cin >> word;

  for (int i = 0; i < word.size(); i++) {
    char c = word[i];

    if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + 'a');
    }
    count[c - 'a'] += 1;
  }

  // for (int i = 0; i < 26; i++) {
  //   cout << "[+] " << (char)(i + 'a') << ": " << count[i] << endl;
  // }

  for (int i = 0; i < 26; i++) {
    if (max_n < count[i]) {
      max_n = count[i];
      ans = 'A' + i;
    } else if (max_n == count[i] && count[i] != 0) {
      ans = '?';
    }
  }

  cout << ans << '\n';
  return 0;
}

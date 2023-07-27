#include <iostream>
#include <list>

using namespace std;

string input;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    list<char> password;
    auto cursor = password.begin();

    cin >> input;
    for (auto c: input) {
      if (c == '<') {
        if (cursor != password.begin()) {
          cursor--;
        }
      }

      else if (c == '>') {
        if (cursor != password.end()) {
          cursor++;
        }
      }

      else if (c == '-') {
        if (cursor != password.begin()) {
          cursor--;
          cursor = password.erase(cursor);
        }
      }

      else {
        cursor = password.insert(cursor, c);
        cursor++;
      }
    }

    for (auto c: password) {
      cout << c;
    }
    cout << endl;
  }

  return 0;
}

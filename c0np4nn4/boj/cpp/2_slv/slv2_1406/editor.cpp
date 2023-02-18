#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> L;

int main() {

  string s;
  cin >> s;

  L.push_back('_');

  for (auto c: s) {
    L.push_back(c);
  }

  list<int>::iterator cursor;

  for (cursor = L.begin(); cursor != L.end(); cursor++);
  cursor--;

  int m;
  cin >> m;

  while (m > 0) {
    char c;
    cin >> c;

    switch(c) {
      case 'L':
        if (cursor != L.begin())
          cursor--;
        break;

      case 'D':
        if (cursor != L.end())
          cursor++;
        if (cursor == L.end())
          cursor--;
        break;

      case 'B':
        if (cursor == L.begin()) {
          break;
        }

        if (cursor == L.end()) {
          cursor--;
          cursor = L.erase(cursor);
        }

        else {
          cursor = L.erase(cursor);
          cursor--;
        }

        break;

      case 'P':
        char c;
        cin >> c;

        if (cursor != L.end())
          cursor++;

        cursor = L.insert(cursor, c);
        break;
    }

    // cout << "\n\n=-=-=-=[STATE]=-=-=-=\n";
    // cout << "     " <<  (char) *cursor << " | ... "<< endl;
    // for(auto c: L) {
    //   cout << (char) c << ' ';
    // }
    // cout << '\n';

    m--;
  }

  auto ans = L.begin();
  ans++;

  while (ans != L.end()) {
    cout << (char) *ans;
    ans++;
  }
  cout << '\n';

  return 0;
}

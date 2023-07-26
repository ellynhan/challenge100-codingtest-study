#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
stack<int> S;

void input()
{
  cin >> N;
  string op;
  int num;
  FOR(n, N) {
    cin >> op;
    if (op == "push") {
      cin >> num;
      S.push(num);      
    } else if (op == "top") {
      if (S.empty()) {
        cout << -1 << '\n';
      } else {
        cout << S.top() << '\n';
      }
    } else if (op == "size") {
      cout << (int)S.size() << '\n';
    } else if (op == "empty") {
      cout << (int)S.empty() << '\n';
    } else if (op == "pop") {
      if (S.empty()) {
        cout << -1 << '\n';
      } else {
        cout << S.top() << '\n';
        S.pop();
      }
    }

  }
  return;
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  return 0;
}
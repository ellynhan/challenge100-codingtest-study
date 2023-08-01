#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N;
queue<int> Q;

void input()
{
  cin >> N;
  FOR(n, N) {
    Q.push(n + 1);
  }
}

void solve()
{
  bool flag = false;
  while(Q.size() != 1) {
    int next = Q.front();
    Q.pop();
    if (flag) {
      Q.push(next);
    }
    flag = !flag;
  }
}

void print()
{
  cout << Q.front() << '\n';
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}
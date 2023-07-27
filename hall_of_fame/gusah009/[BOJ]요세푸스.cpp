#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, K;
queue<int> Q;

void input()
{
  cin >> N >> K;
  FOR(n, N) {
    Q.push(n + 1);
  }
}

void solve()
{
  cout << '<';
  int k = 1;
  while(!Q.empty()) {
    int node = Q.front();
    Q.pop();
    if (k == K) {
      cout << node;
      if (!Q.empty()) cout << ", ";
      k = 0;
    } else {
      Q.push(node);
    }
    k++;
  }
  cout << '>';
}

void print()
{

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
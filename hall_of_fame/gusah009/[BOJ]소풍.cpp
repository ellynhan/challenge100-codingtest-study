#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 1; i <= j; i++)

int K, N, F;
int friends[901][901] = {0};
vector<int> friends2[901];
set<int> answer;

void input()
{
  cin >> K >> N >> F;
  int A, B;
  FOR(f, F) {
    cin >> A >> B;
    friends[A][B] = 1;
    friends[B][A] = 1;
    friends2[A].push_back(B);
    friends2[B].push_back(A);
  }

  FOR(n, N) {
    friends[n][n] = 1;
  }
  
  FOR(n, N) {
    sort(friends2[n].begin(), friends2[n].end());
  }
}

bool DFS(int n)
{
  // cout << n << '!' << '\n';
  if (answer.find(n) != answer.end()) {
    return false;
  }

  for (auto it = answer.begin(); it != answer.end(); it++) {
    if (friends[*it][n] != 1) {
      return false;
    }
  }

  answer.insert(n);


    // for (auto it = answer.begin(); it != answer.end(); it++) {
    //   cout << *it << ' ';
    // }
    // cout << '\n';

  if (answer.size() == K) {
    return true;
  }

  for (int i = 0; i < friends2[n].size(); i++) {
    if (friends2[friends2[n][i]].size() >= K - 1) {
      if (DFS(friends2[n][i])) {
        return true;
      }
    }
  }
  
  answer.erase(n);

  return false;
}

void solve()
{
  FOR(n, N) {
    if (friends2[n].size() >= K - 1) {
      if (DFS(n)) {
        return;
      }
    }
  }
}

void print()
{
  if (answer.size() == K) {
    for (auto it = answer.begin(); it != answer.end(); it++) {
      cout << *it << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
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
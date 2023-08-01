#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N;
vector<int> edge[1000001];
bool visited[1000001] = {0};

void input()
{
  cin >> N;
  int A, B;
  FOR(n, N - 1) {
    cin >> A >> B;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
}

// 내가 얼리어댑터인 경우 / 아닌 경우
pair<int, int> DFS(int node)
{
  
  visited[node] = true;
  if (edge[node].size() == 1) {
    return {1, 0};
  }

  pair<int, int> ret = {1, 0};
  // cout << node << '\n';
  FOR(i, edge[node].size()) {
    if (!visited[edge[node][i]]) {
      pair<int, int> tmp = DFS(edge[node][i]);
      // cout << tmp.first << ' ' << tmp.second << '\n';
      ret.first += min(tmp.first, tmp.second);
      ret.second += tmp.first;
    }
  }

  return ret;
}

void solve()
{
  if (N == 2) {
    cout << 1 << '\n';
    return;
  }
  int start = 1;
  FOR(n, N + 1) {
    if (edge[n].size() > 1) {
      start = n;
      break;
    }
  }
  pair<int, int> tmp = DFS(start);
  cout << min(tmp.first, tmp.second) << '\n';
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
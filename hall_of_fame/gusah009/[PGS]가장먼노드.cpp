#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N;
vector<int> edge[20001];
int DP[20001];
int answer = 0;

void input()
{
  cin >> N;
  int a, b;
  while(cin >> a >> b) {
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  FOR(i, 20001) DP[i] = INF;
}

void solve()
{
  priority_queue<pair<int, int> > PQ;
  PQ.push({1, 0});
  DP[0] = 0;
  DP[1] = 0;
  while(!PQ.empty()) {
    int node = PQ.top().first;
    int dist = PQ.top().second;
    PQ.pop();

    if (DP[node] < dist) continue;
    DP[node] = dist;

    FOR(i, edge[node].size()) {
      PQ.push({edge[node][i], dist + 1});
    }
  }

  int maximum = 0;
  FOR(i, N + 1) {
    maximum = max(maximum, DP[i]);
  }
  
  FOR(i, N + 1) {
    if (DP[i] == maximum) answer++;
  }
}

void print()
{
  cout << answer << '\n';
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
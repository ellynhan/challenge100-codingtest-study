#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)

int N, M;
int answer = 0;
int parent[500001] = {0};
pair<int, int> edge[1000001];

void input()
{
  cin >> N >> M;

  int x, y;
  FOR(m, M) {
    cin >> x >> y;
    if (x < y) edge[m] = {x, y};
    else       edge[m] = {y, x};
  }
}

int findParent(int node)
{
	if (node == parent[node])
		return node;

	return parent[node] = findParent(parent[node]);
}

void solve()
{
  FOR(n, N + 1) {
    parent[n] = n;
  }

  int x, y, parent_x, parent_y;
  FOR(m, M) {
    x = edge[m].first;
    y = edge[m].second;
    parent_x = findParent(x);
    parent_y = findParent(y);
    
    if (parent_x == parent_y) {
      answer = m + 1;
      return;
    }
    parent[parent_x] = parent[parent_y];
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
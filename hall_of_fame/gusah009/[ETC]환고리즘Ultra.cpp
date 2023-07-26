#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX_VERTEX 26
#define START 0
#define INF 1987654321

int N, M;
int isVisited = 0;
int isVisitedTmp = 0;
int startNode = 0;
int dist[MAX_VERTEX];
vector<pair<int, int> > graph[MAX_VERTEX];
vector<pair<int, int> > deadPath;
int deadVertex[MAX_VERTEX] = {0};
pair<int, int> noPath;
int answer = 0;
int paramV, paramW;
int deadV = 0, reachV = 0;

void input()
{
  cin >> N >> M;
  char v1, v2;
  int w;
  FOR(m, M) {
    cin >> v1 >> v2 >> w;
    graph[v1 - 'a'].push_back({w, v2 - 'a'});
    graph[v2 - 'a'].push_back({w, v1 - 'a'});
  }
}

void DFS(int w, int v)
{
  if (v == START) {
    answer = max(answer, w);
    return;
  }

  if (!(startNode & (1 << v)) && ((startNode & isVisited) == startNode)) return;

  if ((deadVertex[v] & isVisited) != 0) return;

  for (auto next: graph[v]) {
    if (!(isVisited & (1 << next.second))) {
      isVisited |= (1 << next.second);
      DFS(w + next.first, next.second);
      isVisited &= ~(1 << next.second);
    }
  }
}

void findDeadPath(int v) {

  isVisitedTmp |= (1 << v);

  for (auto next: graph[v]) {
    if (!(isVisitedTmp & (1 << next.second)) &&
        (noPath != make_pair(v, next.second) &&
         noPath != make_pair(next.second, v))) {
      findDeadPath(next.second);
    }
  }
}

void findDeadVertex(int v) {
  isVisitedTmp |= (1 << v);

  for (auto next: graph[v]) {
    if (!(isVisitedTmp & (1 << next.second)) &&
        next.second != deadV) {
      findDeadVertex(next.second);
    }
  }
}

void solve()
{ 
  for (auto next: graph[START]) {
    startNode |= (1 << next.second);
  }

  int everyVertex = 0;
  FOR(v, MAX_VERTEX) {
    if (!graph[v].empty()) {
      everyVertex |= (1 << v);
    }
  }

  FOR(v, MAX_VERTEX) {
    for (auto next: graph[v]) {
      isVisitedTmp = 1;
      noPath = {v, next.second};
      findDeadPath(START);
      if (isVisitedTmp != everyVertex) {
        deadPath.push_back(noPath);
      }
    }
  }

  for (auto next: deadPath) {
    for (auto it = graph[next.first].begin(); it != graph[next.first].end(); it++) {
      if (it->second == next.second) {
        it = graph[next.first].erase(it);
        it--;
      }
    }
  }

  for (deadV = 1; deadV < MAX_VERTEX; deadV++) {
    if (!graph[deadV].empty()) {
      isVisitedTmp = 1;
      findDeadVertex(START);
      for (reachV = 0; reachV < MAX_VERTEX; reachV++) {
        if ((deadV != reachV) && !((isVisitedTmp >> reachV) & 1)) {
          deadVertex[reachV] |= (1 << deadV);
        }
      }
    }
  }
  
  for (auto next: graph[START]) {
    isVisited |= (1 << next.second);
    DFS(next.first, next.second);
    isVisited &= ~(1 << next.second);
  }
}

void print()
{
  cout << answer << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();

  return 0;
}
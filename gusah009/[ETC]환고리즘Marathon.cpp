#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define MAX_VERTEX 26
#define MARA_DIST 42
#define START 0
#define INF 1987654321

int N, M;
int isVisited[MAX_VERTEX] = {0};
int dist[MAX_VERTEX];
vector<pair<int, int> > graph[MAX_VERTEX];
pair<int, string> path = {0, "00000000000000000000000000"};
pair<int, string> answer = {0, "00000000000000000000000000"};

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

void setAnswer()
{
  if (path.first == answer.first) {
    if (path < answer) {
      answer = path;
    }
  } else if (path.first > answer.first) {
    answer = path;
  }
}

void DFS(int w, int v)
{
  if (v == 0) {
    if (w == MARA_DIST) setAnswer();
    return;
  } 

  if (w + dist[v] > MARA_DIST) {
    return;
  }

  for (auto next: graph[v]) {
    if (!isVisited[next.second]) {
      isVisited[next.second] = true;
      path.second[path.first] = next.second;
      path.first++;
      DFS(w + next.first, next.second);
      isVisited[next.second] = false;
      path.first--;
    }
  }
}

void dijkstra()
{
  fill(dist, dist + MAX_VERTEX, INF);
  priority_queue<pair<int, int>> PQ;
  PQ.push(make_pair(0, START));
  dist[START] = 0;

  while (PQ.empty() == 0) {
    int w = -PQ.top().first;
    int v = PQ.top().second;
    PQ.pop();

    for (int i = 0; i < graph[v].size(); i++) {
      int Next = graph[v][i].second;
      int nextW = graph[v][i].first;

      if (dist[Next] > w + nextW) {
        dist[Next] = w + nextW;
        PQ.push(make_pair(-dist[Next], Next));
      }
    }
  }
}

void solve()
{
  dijkstra();
  
  for (auto next: graph[START]) {
    isVisited[next.second] = true;
    path.second[path.first] = next.second;
    path.first++;
    DFS(next.first, next.second);
    isVisited[next.second] = false;
    path.first--;
  }
}

void print()
{
  if (answer.first == 0) cout << "None\n";
  else {
    cout << answer.first << '\n';
    cout << "a ";
    FOR(i, answer.first - 1) {
      cout << char(answer.second[i] + 'a') << ' ';
    }
    cout << '\n';
  }
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
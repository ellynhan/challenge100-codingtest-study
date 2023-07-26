#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)
#define START 1
#define INF 1987654321

int N, W;
double M;

vector<int> edge[1001];
pair<int, int> coordinate[1001];
double dist[1001][1001];
double shortestDist[1001];

void input()
{
  cin >> N >> W;
  cin >> M;

  int x, y;
  FOR(n, N)
  {
    cin >> x >> y;
    coordinate[n + 1] = {x, y};
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      double tmp = sqrt(pow(coordinate[i].first - coordinate[j].first, 2) +
                        pow(coordinate[i].second - coordinate[j].second, 2));
      dist[i][j] = tmp > M ? INF : tmp;
    }
  }

  int a, b;
  FOR(w, W)
  {
    cin >> a >> b;
    dist[a][b] = 0;
    dist[b][a] = 0;
  }
}

void solve()
{
  for (int i = 0; i < 1001; i++) shortestDist[i] = INF;
  shortestDist[1] = 0;

  queue<pair<int, double>> q;
  q.push(make_pair(START, 0));

  while (!q.empty())
  {
    int here = q.front().first;
    double cost = q.front().second;
    q.pop();

    if (shortestDist[here] < cost) continue;

    for (int i = 1; i <= N; i++)
    {
      int there = i;
      double nextdist = cost + dist[here][i];
      if (shortestDist[there] > nextdist)
      {
        shortestDist[there] = nextdist;
        q.push(make_pair(there, nextdist));
      }
    }
  }
 //출처: https: //qkqhxla1.tistory.com/666 [archives]
}

void print()
{
  cout << int(shortestDist[N] * 1000) << '\n';
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  print();
}
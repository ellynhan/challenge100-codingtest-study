#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j) for (int i = 0; i < j; i++)

int N;
pair<double, double> star[100];
int parent[10002];
double res = 0;
bool chk;

typedef struct kruskal
{
  int from;
  int to;
  double val;
} KS;

vector<KS> edge;

bool comp(KS d1, KS d2)
{
  return d1.val < d2.val;
}

// 파인드
int find(int u)
{
  if (u == parent[u])
    return u;

  return parent[u] = find(parent[u]);
}

// 유니온
void merge(int u, int v)
{
  chk = false;
  u = find(u);
  v = find(v);

  // 사이클 존재 여부 확인 코드
  if (u == v)
    return;

  parent[u] = v;
  chk = true;
}

void input()
{
  cin >> N;
  FOR(n, N)
  {
    cin >> star[n].first;
    cin >> star[n].second;
  }
}

double calDist(double x1, double y1, double x2, double y2)
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve()
{
  FOR(i, N)
  {
    FOR(j, N)
    {
      KS dist;
      dist.from = i;
      dist.to = j;
      dist.val = calDist(star[i].first, star[i].second, star[j].first, star[j].second);
      edge.push_back(dist);
    }
  }

  // 부모를 자기 자신으로 초기화
  FOR(n, N) parent[n] = n;

  // 크루스칼 알고리즘에 의해 간선을 오름차순 정렬
  sort(edge.begin(), edge.end(), comp);

  // 간선 union, 사이클이 존재하지 않도록
  for (int i = 0; i < N * N; i++)
  {
    merge(edge[i].from, edge[i].to);

    if (chk) {
      res += edge[i].val;
    }
  }
}

void print()
{    
  cout << fixed;
  cout.precision(8);
  cout << res << '\n';
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
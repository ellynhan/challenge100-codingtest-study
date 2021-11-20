#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

int N, M;
int edge[1001][1001] = {0};
vector<int> noConnections;
int fullConnection = 0;
set<int> setA, setB;
bool impossibleFlag = true;

bool DFS(int node, int depth)
{
  FOR(n, N) {
    int tmp = edge[node][n];
    if (depth % 2 == 0) {
      if (tmp == 0) {
        for (auto it = setA.begin(); it != setA.end(); it++) {
          if (edge[n][*it] == 0 || edge[n][*it] == 2) {
            return false;
          }
        }
        edge[node][n] = 2;
        edge[n][node] = 2;
        setA.insert(n);
        impossibleFlag = DFS(n, depth + 1);
        if (!impossibleFlag) return false;
      }
    } else {
      if (tmp == 0) {
        for (auto it = setB.begin(); it != setB.end(); it++) {
          if (edge[n][*it] == 0 || edge[n][*it] == 2) {
            return false;
          }
        }
        edge[node][n] = 2;
        edge[n][node] = 2;
        setB.insert(n);
        impossibleFlag = DFS(n, depth + 1);
        if (!impossibleFlag) return false;
      }
    }
  }
  return true;
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  int point1, point2;
  FOR(m, M) {
    cin >>  point1 >> point2;
    edge[point1 - 1][point2 - 1] = 1;
    edge[point2 - 1][point1 - 1] = 1;
  }

  FOR(i, N) {
    edge[i][i] = 1;
  }

  FOR(i, N) {
    bool flag = true;
    FOR(j, N) {
      if (edge[i][j] == 0) {
        setA.clear();
        setB.clear();
        setA.insert(i);
        setB.insert(j);
        edge[i][j] = 2;
        edge[j][i] = 2;
        impossibleFlag = DFS(i, 1);
        if (!impossibleFlag) {
          cout << -1 << '\n';
          return 0;
        }
        impossibleFlag = DFS(j, 0);
        if (!impossibleFlag) {
          cout << -1 << '\n';
          return 0;
        }
        int A = setA.size();
        int B = setB.size();
        noConnections.push_back(abs(A - B));
        
        flag = false;
      }
      if (edge[i][j] == 2) flag = false;
    }
    if (flag) fullConnection++;
  }

  // Knapsack?
  sort(noConnections.begin(), noConnections.end(), greater<int>());
  int A = 0, B = 0;
  
  FOR(i, noConnections.size()) {
    if (A > B) {
      B += noConnections[i];
    } else {
      A += noConnections[i];
    }
  }
  
  int answer = abs(A - B);
  answer -= fullConnection;
  if (answer <= 0) {
    if (N % 2 == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
  } else {
    cout << answer << '\n';
  }
  return 0; 
}
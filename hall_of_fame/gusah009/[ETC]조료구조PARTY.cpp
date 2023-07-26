#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 87654321
#define SIZE 24
#define FRIENDS_COUNT 3

int N;
int edge[SIZE][SIZE] = {0};
int dist[SIZE][SIZE] = {0};
int f[FRIENDS_COUNT] = {0};
int index = 0;
map<char, int> vertexToIndex;
map<int, char> indexToVertex;
pair<int, char> answer = {INF - 100000, '@'};

int mappingVertexToIndex(char inp)
{
  int vertex;
  if (vertexToIndex.find(inp) != vertexToIndex.end()) {
    vertex = vertexToIndex[inp];
  } else {
    vertexToIndex.insert({inp, index});
    indexToVertex.insert({index, inp});
    vertex = index;
    index++;
  }
  return vertex;
}

void input()
{
  cin >> N;

  char inp;
  FOR(i, FRIENDS_COUNT) {
    cin >> inp;
    f[i] = mappingVertexToIndex(inp);
  }

  FOR(i, N) {
    FOR(j, N) {
      edge[i][j] = INF;
      if (i == j) edge[i][j] = 0;
    }
  }

  int startVertex, adjacentVertex;
  FOR(n, N) {
    cin >> inp;
    startVertex = mappingVertexToIndex(inp);
    while(true) {
      cin >> inp;
      if (inp == '$') break;
      adjacentVertex = mappingVertexToIndex(inp);

      edge[startVertex][adjacentVertex] = 3;
      edge[adjacentVertex][startVertex] = 3;
    } 
  }
}

void solve()
{
  FOR(i, N) {
    FOR(j, N) {
      dist[i][j] = edge[i][j];    
    }
  }

  FOR(k, N) {
    FOR(i, N) {
      FOR(j, N) {
        // if (i != k && j != k && i != j) {
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        // }
      }
    }
  }
  
  FOR(n, N) {
    int d = -INF;
    FOR(i, FRIENDS_COUNT) {
      d = max(d, dist[f[i]][n] - 2);
    }
    if (answer.first > d) {
      answer.first = d;
      answer.second = indexToVertex[n];
    } else if (answer.first == d) {
      if (answer.second > indexToVertex[n]) {
        answer.first = d;
        answer.second = indexToVertex[n];
      }
    }
  }

  // FOR(j, N) {
  //   cout << indexToVertex[j] << ' ';
  // }
  // cout << '\n';
  // FOR(i, N) {
  //   FOR(j, N) {
  //     cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}

void print()
{
  if (answer.second == '@')
    cout << '@' << '\n' << -1 << '\n';
  else
    cout << answer.second << '\n' << answer.first << '\n';
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
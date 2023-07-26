#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;
bool maze[100][100];
int walk[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      walk[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;

    for (int j = 0; j < m; j++) {
      maze[i][j] = line[j] - '0';
    }
  }

  Q.push({0,0});
  walk[0][0] = 1;

  while (!Q.empty()) {
    pair<int, int> cur = Q.front();

    Q.pop();

    // cout << "\n_x: " << cur.first << ", _y: " << cur.second << endl;
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (!maze[nx][ny] || walk[nx][ny] > 0) continue;

      walk[nx][ny] = walk[cur.first][cur.second] + 1;

      // cout << "nx: "<< nx << ", ny: "<< ny <<  " walk: " << walk[nx][ny] << endl;
      Q.push({nx, ny});
    }
  }

  cout << walk[n-1][m-1] << '\n';

  return 0;
}

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[101][101][101];
int day[101][101][101];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> Q;

int m, n, h;

int main() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 100; k++) {
        box[i][j][k] = -1;
      }
    }
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        cin >> box[i][j][k];
        day[i][j][k] = -1;

        if (box[i][j][k] == 1) {
          Q.push({i, j, k});
          day[i][j][k] = 0;
        }
      }
    }
  }

  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    int x = get<0>(cur);
    int y = get<1>(cur);
    int z = get<2>(cur);

    // cout << "\n[+] x: " << x << ", y: " << y << ", z: " << z << endl;

    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if (nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= m || nz >= n) continue;
      if (day[nx][ny][nz] > 0) continue;
      if (box[nx][ny][nz] != 0) continue;


      box[nx][ny][nz] = 1;

      day[nx][ny][nz] = (day[x][y][z] + 1);

      Q.push({nx, ny, nz});
    }
  }


  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        // cout << box[i][j][k] << ' ';
        if (day[i][j][k] < 0 && box[i][j][k] == 0) {
          cout << -1 << endl;
          return 0;
        }
        if (day[i][j][k] > ans) {
          ans = day[i][j][k];
        }
      }
    }
  }

  cout << ans << '\n';


  return 0;
}

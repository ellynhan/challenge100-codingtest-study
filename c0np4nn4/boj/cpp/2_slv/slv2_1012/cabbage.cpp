#include <iostream>
#include <queue>

using namespace std;

int field[51][51];
int vis[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> pos;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    // init 
    for (int i = 0; i < 51; i++) {
      for (int j = 0; j < 51; j++) {
        field[i][j] = 0;
        vis[i][j] = 0;
      }
    }

    while (!pos.empty()) {
      pos.pop();
    }

    int ans = 0;

    int m, n, k;
    cin >> m >> n >> k;

    while (k--) {
      int x, y;
      cin >> x >> y;

      field[x][y] = 1;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (field[i][j] == 1 && vis[i][j] == 0) {
          // cout << "new axis, i: " << i << ", j: " << j << endl;
          vis[i][j] = 1;
          pos.push({i, j});

          while (!pos.empty()) {
            auto cur = pos.front(); pos.pop();
            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++) {
              int nx = x + dx[i];
              int ny = y + dy[i];

              if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
              if (vis[nx][ny] == 1) continue;
              if (field[nx][ny] == 0) continue;

              vis[nx][ny] = 1;
              pos.push({nx, ny});
            }
          }
          ans += 1;
        }
      }
    }

  //   cout << endl;
  //   for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //       cout << field[i][j] << ' ';
  //     }
  //     cout << endl;
  //   }
    cout << ans << '\n';
  }

  return 0;
}

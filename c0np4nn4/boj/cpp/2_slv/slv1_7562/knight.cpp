#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;

int cnt[301][301];

int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int l;
    cin >> l;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        cnt[i][j] = -1;
      }
    }

    int sx, sy;
    cin >> sx >> sy;

    cnt[sx][sy] = 0;
    Q.push({sx, sy});

    int tx, ty;
    cin >> tx >> ty;


    while (!Q.empty()) {
      auto cur = Q.front(); Q.pop();

      int x = cur.first;
      int y = cur.second;

      if (x == tx && y == ty) break;

      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >=l || ny >= l) continue;
        if (cnt[nx][ny] > 0) continue;

        cnt[nx][ny] = cnt[x][y] + 1;

        if (nx == tx && ny == ty) break;

        Q.push({nx, ny});
      }
    }

    cout << cnt[tx][ty] << '\n';
  }
  return 0;
}

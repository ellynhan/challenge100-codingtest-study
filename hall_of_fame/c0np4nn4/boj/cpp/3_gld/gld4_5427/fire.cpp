#include <iostream>
#include <queue>

using namespace std;

char map[1002][1002];
long long walk[1002][1002];
long long fire[1002][1002];

queue<pair<int, int>> M;
queue<pair<int, int>> F;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    // init
    int ans = 2147483647;

    for (int i = 0; i < 1001; i++) {
      for (int j = 0; j < 1001; j++) {
        map[i][j] = ' ';
        walk[i][j] = -1;
        fire[i][j] = 9999;
      }
    }

    int w, h;
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      string line;
      cin >> line;

      for (int j = 0; j < w; j++) {
        char c = line[j];
        map[i][j] = c;

        if (c == '@') {
          if (i == 0 || j == 0 || i == h-1 || j == w-1)
            ans = 1;

          M.push({i, j});
          walk[i][j] = 1;
        }

        if (c == '*') {
          F.push({i, j});
          fire[i][j] = 1;
        }
      }
    }

    // 1. fire
    while (!F.empty()) {
      auto cur = F.front(); F.pop();
      int x = cur.first;
      int y = cur.second;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (map[nx][ny] == '#') continue;
        if (fire[nx][ny] != 9999) continue;

        fire[nx][ny] = fire[x][y] + 1;
        F.push({nx, ny});
      }
    }

    // 2. Walk
    while (!M.empty()) {
      auto cur = M.front(); M.pop();
      int x = cur.first;
      int y = cur.second;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (map[nx][ny] == '#') continue;
        if (walk[nx][ny] >= 1) continue;

        walk[nx][ny] = walk[x][y] + 1;

        if (nx == 0 || ny == 0 || nx == h-1 || ny == w-1) {
          if (fire[nx][ny] > walk[nx][ny]) {
            if (ans > walk[nx][ny])
              ans = walk[nx][ny];
          }
        }

        M.push({nx, ny});
      }
    }

    if (ans == 2147483647) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}

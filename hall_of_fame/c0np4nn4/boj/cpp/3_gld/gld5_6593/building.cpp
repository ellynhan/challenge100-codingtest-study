#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int l = 1;
int r = 1;
int c = 1;

char building[31][31][31];
int lapsed[31][31][31];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int ex, ey, ez;

queue<tuple<int, int, int>> Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (l != 0 || r != 0 || c != 0) {
    // init
    ex = 0; ey = 0; ez = 0;
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
          building[i][j][k] = '#';
          lapsed[i][j][k] = 0;
        }
      }
    }

    cin >> l >> r >> c;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        string line;
        cin >> line;

        for (int k = 0; k < c; k++) {
          building[i][j][k] = line[k];

          if (building[i][j][k] == 'S') {
            lapsed[i][j][k] = 0;
            building[i][j][k] = '#';
            Q.push({i, j, k});
          }

          if (building[i][j][k] == 'E') {
            ex = i;
            ey = j;
            ez = k;
          }
        }
      }
    }

    while (!Q.empty()) {

      if (lapsed[ex][ey][ez] != 0) {
        // cout << "find the value" << endl;
        break;
      }

      // cout << "\nQ size: " << Q.size() << endl;
      auto cur = Q.front(); Q.pop();
      // cout << "Q size: " << Q.size() << endl;
      int x = get<0>(cur);
      int y = get<1>(cur);
      int z = get<2>(cur);

      // cout << "[+] cur: " << x << ", " << y << ", " << z << ", lapsed: " << lapsed[x][y][z] << endl;

      for (int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];


        if (nx < 0 || ny < 0 || nz < 0) continue;
        if (nx >= l || ny >= r || nz >= c) continue;
        if (lapsed[nx][ny][nz] > 0) continue;
        if (building[nx][ny][nz] == '#') continue;

        // cout << "[+] new point: " << nx << ", " << ny << ", " << nz << endl;

        lapsed[nx][ny][nz] = lapsed[x][y][z] + 1;
        Q.push({nx, ny, nz});
      }
    }

    if (lapsed[ex][ey][ez] != 0) {
      // cout << "Escaped in " << lapsed[ex][ey][ez] << " minute(s).\n";
      cout << "Escaped in " << lapsed[ex][ey][ez] << " minute(s)." << endl;
    } else if (l != 0 && r != 0 && c != 0) {
      cout << "Trapped!" << endl;
    }
  }


  return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canvas[500][500];
bool vis[500][500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> Q;

int ans;
int cnt;

vector<pair<int, int>> black_points;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> canvas[i][j];
      if (canvas[i][j]) {
        black_points.push_back({i, j});
      }
    }
  }


  // for (auto point: black_points) {
  for (int k = 0; k < black_points.size(); k++) {
      pair<int, int> point = black_points[k];
      int i = point.first;
      int j = point.second;

      // cout << "\ni: " << i << ", j: " << j << endl;

      int area = 1;

      if (canvas[i][j] && !vis[i][j]) {
        cnt += 1;

        Q.push(make_pair(i, j));

        vis[i][j] = true;

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int t = 0; t < 4; t++) {
            int nx = cur.first + dx[t];
            int ny = cur.second + dy[t];


            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (!canvas[nx][ny]) continue;
            if (vis[nx][ny]) continue;

            area += 1;

            vis[nx][ny] = true;
            Q.push({nx, ny});
            // cout << "nx: " << nx << ", ny: " << ny << endl;
          }
        }

        if (ans < area) {
          ans = area;
        }
      }

    }
  // }

  cout << cnt << endl;
  cout << ans << endl;


  return 0;
}

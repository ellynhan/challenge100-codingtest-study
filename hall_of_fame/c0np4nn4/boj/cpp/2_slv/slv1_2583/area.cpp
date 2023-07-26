#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int m, n, k;

queue<pair<int, int>> Q;

int plane[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int area;
int cnt;

vector<int> ans;

void print_plane() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << plane[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n >> k;

  while (k--) {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    // cout << endl;
    for (int i = y1; i < y2; i++) {
      for (int j = x1; j < x2; j++) {
        // cout << "(" << i << ", " << j << ")" << endl;
        plane[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      area = 0;

      while (!Q.empty()) Q.pop();

      if (plane[i][j] == 0) {
        Q.push({i, j});

        cnt++;
        plane[i][j] = 1;
        area = 1;
      }

      // cout << endl;
      while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int x = cur.first;
        int y = cur.second;


        // area = plane[x][y];

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
          if (plane[nx][ny] != 0) continue;

          plane[nx][ny] = ++area;

          // cout << "\n[+] x: " << nx << ", y: " << ny << endl;
          // print_plane();

          Q.push({nx, ny});
        }
      }
      // cout << "i: " << i << ", j: " << j << endl;

      if (area != 0)
        ans.push_back(area);
    }
  }

  cout << cnt << '\n';
  sort(ans.begin(), ans.end());

  for (auto v: ans) {
    cout << v << ' ';
  }
  cout << '\n';




  return 0;
}

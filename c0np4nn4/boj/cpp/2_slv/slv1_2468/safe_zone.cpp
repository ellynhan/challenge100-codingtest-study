#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n;
int map[101][101];
// bool sink[101][101];
bool dry[101][101];

set<int> height;
queue<pair<int, int>> Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int ans;

void print_dry() {
  cout << "=-=-=-=-=-=-=-= dry =-=-=-=-=-=-=-=" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dry[i][j] << ' ';
    }
    cout << endl;
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];

      height.insert(map[i][j]);
    }
  }

  for (auto h: height) {
    // init
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // sink[i][j] = false;
        dry[i][j] = false;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // if (map[i][j] <= h) {
        //   sink[i][j] = true;
        //   Q.push({i, j});
        // }
        if (map[i][j] > h && dry[i][j] == false) {
          cnt++;
          dry[i][j] = true;
          Q.push({i, j});
        }

        while (!Q.empty()) {
          auto cur = Q.front(); Q.pop();
          int x = cur.first;
          int y = cur.second;

          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            // if (sink[nx][ny]) continue;
            if (dry[nx][ny]) continue;
            if (map[nx][ny] <= h) continue;

            dry[nx][ny] = true;
            Q.push({nx, ny});
          }
        }
      }
    }

    // print_dry();

    if (cnt > ans) {
      ans = cnt;
    }
  }

  if (ans == 0) ans = 1;

  cout << ans << '\n';

  return 0;
}

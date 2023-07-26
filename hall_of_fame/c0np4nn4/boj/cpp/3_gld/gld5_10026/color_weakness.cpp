#include <iostream>
#include <queue>

using namespace std;

char board[101][101];
bool vis[101][101];

queue<pair<int, int>> Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int cnt_1;
int cnt_2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);


  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;

    for (int j = 0; j < n; j++) {
      board[i][j] = line[j];
    }
  }

  // cnt 1
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      vis[i][j] = false;
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] == false) {
        vis[i][j] = true;
        Q.push({i, j});

        while (!Q.empty()) {
          auto cur = Q.front(); Q.pop();
          int x = cur.first;
          int y = cur.second;

          char color = board[x][y];

          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny > n) continue;
            if (board[nx][ny] != color) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
          }
        }

        cnt_1++;
      }
    }
  }

  cout << cnt_1 << endl;

  // cnt 2
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vis[i][j] = false;
    }
  }

  while (!Q.empty()) Q.pop();


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cout << "i: " << i << ", j: " << j << ", vis: " << vis[i][j] << endl;

      if (vis[i][j] == false) {
        vis[i][j] = true;
        Q.push({i, j});

        // cout << "[_] i: " << i << ", j: " << j << ", color: " << board[i][j] << endl;

        while (!Q.empty()) {
          auto cur = Q.front(); Q.pop();
          int x = cur.first;
          int y = cur.second;

          char color = board[x][y];

          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            if (color == 'R' && board[nx][ny] == 'B') continue;
            if (color == 'G' && board[nx][ny] == 'B') continue;
            if (color == 'B' && board[nx][ny] == 'R') continue;
            if (color == 'B' && board[nx][ny] == 'G') continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
          }
        }

        // cout << "=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        // for (int i = 0; i < n; i++) {
        //   for (int j = 0; j < n; j++) {
        //     cout << vis[i][j] << ' ';
        //   }
        //   cout << endl;
        // }

        cnt_2++;
      }
    }
  }

  cout << cnt_2 << endl;



  return 0;
}

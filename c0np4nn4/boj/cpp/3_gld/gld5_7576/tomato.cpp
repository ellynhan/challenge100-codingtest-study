#include <iostream>
#include <queue>

using namespace std;

int n, m;

int box[1001][1001];
int day[1001][1001];
queue<pair<int, int>> Q;
queue<pair<int, int>> sp;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int ans = 0;

void print_day() {
  cout << "[+] box" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (day[i][j] == -1) cout << "_ ";
      else 
      cout << day[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tomato;
      cin >> tomato;

      if (tomato == 1) {
        Q.push({i, j});
      } 
      if (tomato == 0) {
        day[i][j] = -1;
      }
    }
  }

  while (!Q.empty()) {
    auto sp = Q.front(); Q.pop();

    int x = sp.first;
    int y = sp.second;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > n || ny < 1 || ny > m) continue; 
      if (day[nx][ny] >= 0) continue;

      box[nx][ny] = 1;

      day[nx][ny] = day[x][y] + 1;
      Q.push({nx, ny});

      // print_day();
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (day[i][j] > ans) ans = day[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans == -1) break;
    for (int j = 1; j <= m; j++) {
      if (day[i][j] == -1 ) {
        ans = -1;
        break;
      }
    }
  }

  


  cout << ans << endl;

  return 0;
}
